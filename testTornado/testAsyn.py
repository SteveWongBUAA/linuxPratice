#!/usr/bin/python
#encoding:utf-8

## Copyright (C), 2015-2017, ****.
## project name:    pxg
## Author:          hjx
## Version:         0.2
## Date:            2015-07-24
## Description:     
## History:         0.2
##   1. Date:
##      Author:    hjx
##      Modification:
##   2. ...

host = '10.9.40.166'
db = 'line1'
port = 3306
usr = 'root'
passwd = ''
num = 100
cmd = "select id from devData where id < %d" % num
cmds = "select sleep(1)" 
cmdsn = "select sleep(%s)"

import functools
import tornado.ioloop
import tornado.options
import tornado.web
import tornado.httpserver
import tornado.httpclient
from tornado_mysql import pools
import MySQLdb
import datetime
import os
from concurrent.futures import ThreadPoolExecutor

from tornado.options import define, options
define("port", default=8888, help="run on the given port", type=int)


MYSQL_POOL = pools.Pool(dict(host=host, port=port, user=usr, passwd=passwd, db=db) ,
         max_idle_connections=5, max_open_connections=10)

################################################
# synchronuos
class SyncHandler(tornado.web.RequestHandler):
    def get(self):
        conn = MySQLdb.connect(host, usr, passwd, db, port)
        cur = conn.cursor()
        cur.execute(cmds)
        rep = cur.fetchall()
        self.write({'res': rep})

################################################



################################################
# examples from http://python.jobbole.com/84944/#
class AsynPingWithResHandler(tornado.web.RequestHandler):
    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self, *args, **kwargs):
        print '# in get', datetime.datetime.now()
        # yield 结果
        response = yield tornado.gen.Task(self.ping, 'www.baidu.com')
        print 'response', response
        self.finish('hello')
 
    @tornado.gen.coroutine
    def ping(self, url):
        os.system("ping -c 2 {}".format(url))
        return 'after'

class AsynPingNoResHandler(tornado.web.RequestHandler):
    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self, *args, **kwargs):
 
        tornado.ioloop.IOLoop.instance().add_timeout(1, callback=functools.partial(self.ping, 'www.baidu.com'))
 
        # do something others
 
        self.finish('It works')
 
    @tornado.gen.coroutine
    def ping(self, url):
        os.system("ping -c 2 {}".format(url))
        return 'after'

class AsyncTaskHandler(tornado.web.RequestHandler):
    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self):
        print '# in get', datetime.datetime.now()
        t = self.get_argument('t')
        response = yield tornado.gen.Task(self.query, t)
        print 'response', response
        self.write({'res': response})
        self.finish()

    @tornado.gen.coroutine
    def query(self, t):
        print 'start query', datetime.datetime.now()
        #os.system("ping -c 2 www.baidu.com")
        conn = MySQLdb.connect(host, usr, passwd, db, port)
        print 'conn', datetime.datetime.now().strftime("%S"), conn
        cur = conn.cursor()
        print 'cur', datetime.datetime.now().strftime("%S"), cur
        cur.execute(cmdsn % t)
        print 'exe', datetime.datetime.now().strftime("%S")
        rep = cur.fetchall()
        print 'end query', datetime.datetime.now()
        return rep
        #return 'ok'

class Executor(ThreadPoolExecutor):
    _instance = None

    def __new__(cls, *args, **kwargs):
        if not getattr(cls, '_instance', None):
            cls._instance = ThreadPoolExecutor(max_workers=10)
        return cls._instance

class FuturesHandler(tornado.web.RequestHandler):
    executor = Executor()

    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self):
        print '# in get', datetime.datetime.now()
        t = self.get_argument('t')
        future = Executor().submit(self.query, t)
        response = yield tornado.gen.with_timeout(datetime.timedelta(10), future,
                                                quiet_exceptions=tornado.gen.TimeoutError)
        if response:
            print 'response', response.result()
            self.write({'res': response.result()})

    @tornado.concurrent.run_on_executor
    def query(self, t):
        print 'start query', datetime.datetime.now()
        #os.system("ping -c 2 www.baidu.com")
        conn = MySQLdb.connect(host, usr, passwd, db, port)
        cur = conn.cursor()
        cur.execute(cmdsn % t)
        rep = cur.fetchall()
        print 'end query', datetime.datetime.now()
        return rep

################################################



################################################
# successful solution using module tornado_mysql
class TornMysqlHandler(tornado.web.RequestHandler):
    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self):
        print 'in get', datetime.datetime.now()
        cur = yield MYSQL_POOL.execute(cmds)
        print 'response', cur 
        self.write({'res': cur.fetchall()})
        self.finish()

################################################




################################################
# official tornado website solution 
class OfficialSynHandler(tornado.web.RequestHandler):
    def get(self):
        print '# in get', datetime.datetime.now()
        client = tornado.httpclient.HTTPClient()
        response = client.fetch("http://www.csdn.net/")
        print 'response', response
        self.write('ok')

class OfficialAsynHandler(tornado.web.RequestHandler):
    #@tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self):
        print '# in get', datetime.datetime.now()
        client = tornado.httpclient.AsyncHTTPClient()
        response = yield tornado.gen.Task(client.fetch, "www.csdn.net")
        print 'response', response
        self.write('ok')
        #self.finish()

################################################




################################################
# stackoverflow solution, failed, the backend handler is still blocking
# http://stackoverflow.com/questions/24634764/how-could-i-make-asynchronous-mysql-operations-in-tornado-using-python3-4
class BackendHandler(tornado.web.RequestHandler):
    def get(self):
        #print 'start query', datetime.datetime.now()
        conn = MySQLdb.connect(host, usr, passwd, db, port)
        cur = conn.cursor()
        cur.execute(cmdsn % 1)
        rep = cur.fetchall()
        #print 'end query', datetime.datetime.now()
        self.write({'res': rep})

class FrontendHandler(tornado.web.RequestHandler):
    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def get(self):
        print '# in get', datetime.datetime.now()
        client = tornado.httpclient.AsyncHTTPClient(max_clients=500)
        #response = yield tornado.gen.Task(client.fetch, "http://localhost:8888/backend")
        response = yield client.fetch("http://localhost:8888/backend")
        print 'response', response
        self.finish()

################################################
def main():
    tornado.options.parse_command_line()
    application = tornado.web.Application(
        handlers=[(r"/sync", SyncHandler),
                    (r"/tornmysql", TornMysqlHandler),
                    (r"/futures", FuturesHandler),
                    (r"/asynpingnores", AsynPingNoResHandler),
                    (r"/asynpingwithres", AsynPingWithResHandler),
                    (r"/asynctask", AsyncTaskHandler),
                    (r"/officialasyn", OfficialAsynHandler),
                    (r"/officialsyn", OfficialSynHandler),
                    (r"/backend", BackendHandler),
                    (r"/frontend", FrontendHandler)],
        debug=True
        )
    http_server = tornado.httpserver.HTTPServer(application, xheaders=True)
    http_server.listen(options.port)
    tornado.ioloop.IOLoop.instance().start()

if __name__ == "__main__":
    main()
