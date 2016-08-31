#!/usr/bin/env python
# -*- coding:utf-8 -*-

def getMin(N, S):
    '''
    Function to get the min val after we remove S numbers from N.

    Example:

    >>> getMin('12435863', 3)
    '12353'
    >>> getMin('231183', 3)
    '113'
    >>> getMin('1234567', 3)
    '1234'
    >>> getMin('120083', 3)
    '3'
    >>> getMin('120083', 4)
    '0'
    '''
    src_len = len(N)
    dst_len = src_len - S
    for cnt in range(0, S):
        for i in range(1, len(N)):
            if N[i-1] > N[i]:
                N = N[:i-1] + N[i:]
                break
    if len(N) != dst_len:
        N = N[:dst_len-len(N)]
    while N[0] == '0' and len(N) != 1:
        N = N[1:]
    return N


if __name__ == '__main__':
    import doctest
    doctest.testmod()
    
    
