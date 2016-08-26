#!/usr/bin/env python

import time

def consumer():
    r = ''
    while True:
        n = yield r
        print '[CONSUMER] Consuming ', n
        time.sleep(1)
        r = '200 OK'

def produce(c):
    print 'c.next:', c.next()
    n = 0
    while n < 5:
        n += 1
        print '[PRODUCER] Producing ', n
        r = c.send(n)
        print '[PRODUCER] Consumer return: ', r
    c.close()



if __name__ == '__main__':
    c = consumer()
    produce(c)

