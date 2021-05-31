'''
Author: Devansh Jain (190100044)
Lab 11 1A - Defining Ackerman Function
'''

import sys


def ack(m, n):
    '''
    Recursively compute Ackerman number for inputs m, n
    '''
    if m == 0:
        return n + 1

    if n == 0:
        return ack(m - 1, 1)

    return ack(m - 1, ack(m, n - 1))


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

    print(ack(m, n))
