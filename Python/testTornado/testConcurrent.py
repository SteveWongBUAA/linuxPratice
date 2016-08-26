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

# reference: https://lbolla.info/blog/2013/01/22/blocking-tornado

import tornado.ioloop
import tornado.web
import time

from concurrent.futures import ThreadPoolExecutor
from functools import partial, wraps

EXECUTOR = ThreadPoolExecutor(max_workers=4)

def unblock(f):
    @tornado.web.asynchronous
    @wraps(f)
    def wrapper(*args, **kwargs):
        self = args[0]
        def callback(future):
            self.write(future.result())
            self.finish()

        EXECUTOR.submit(
                    partial(f, *args, **kwargs)
                ).add_done_callback(
                            lambda future: tornado.ioloop.IOLoop().instance().add_callback(
                                    partial(callback, future)
                                )
                        )
    return wrapper



################################################
class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.write("hello world %s" % time.time())

class SleepHandler(tornado.web.RequestHandler):
    @unblock
    def get(self, n):
        time.sleep(float(n))
        return ("Awake! %s" % time.time())
################################################

if __name__ == "__main__":
    application = tornado.web.Application([
        (r"/", MainHandler),
        (r"/sleep/(\d+)", SleepHandler),
        ])
    application.listen(8888)
    tornado.ioloop.IOLoop.instance().start()
