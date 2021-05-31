'''
Author: Devansh Jain (190100044)
Lab 11 1D - Memoization - Counting Ackerman Function calls and table look ups
'''

import sys


# Global counter for calls and look ups
count = 0
lookups = 0


def ack(m, n, table):
    '''
    Compute Ackerman number for inputs m, n using Dynamic Programming
    '''
    global count, lookups
    count = count + 1

    if m == 0:
        table[(m, n)] = n + 1
        return table[(m, n)]

    if n == 0:
        if (m - 1, 1) in table:
            lookups = lookups + 1
            table[(m, n)] = table[(m - 1, 1)]
        else:
            table[(m, n)] = ack(m - 1, 1, table)
        return table[(m, n)]

    if (m, n - 1) in table:
        lookups = lookups + 1
        temp = table[(m, n - 1)]
        if (m - 1, temp) in table:
            lookups = lookups + 1
            table[(m, n)] = table[(m - 1, temp)]
        else:
            table[(m, n)] = ack(m - 1, temp, table)
    else:
        table[(m, n)] = ack(m - 1, ack(m, n - 1, table), table)
    return table[(m, n)]


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print('Usage: python 1a.py <m> <n>')
        print('Both m and n have to be non-negative integers')
        exit(1)

    try:
        m = int(sys.argv[1])
        n = int(sys.argv[2])
    except Exception:
        print('Usage: python 1a.py <m> <n>')
        print('Both m and n have to be non-negative integers')
        exit(0)

    if m < 0 or n < 0:
        print('Usage: python 1a.py <m> <n>')
        print('Both m and n have to be non-negative integers')
        exit(1)

    print('ack({}, {}) = {}'.format(m, n, ack(m, n, {})))
    print('Number of function calls = {}'.format(count))
    print('Number of table look ups = {}'.format(lookups))
