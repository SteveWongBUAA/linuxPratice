#!/usr/bin/env python
from __future__ import print_function

from tornado import ioloop, gen
from tornado_mysql import pools


pools.DEBUG = True


POOL = pools.Pool(
    dict(host='10.9.40.166', port=3306, user='root', passwd='kedaadmin', db='line1'),
    max_idle_connections=1,
    max_recycle_sec=3)


@gen.coroutine
def worker(n):
    for i in range(10):
        t = 1
        print(n, "sleeping", t, "seconds")
        cur = yield POOL.execute("SELECT id from devData where id < %s", (100,))
        print(n, cur.fetchall())


@gen.coroutine
def main():
    workers = [worker(i) for i in range(10)]
    yield workers


ioloop.IOLoop.current().run_sync(main)
print(POOL._opened_conns)
