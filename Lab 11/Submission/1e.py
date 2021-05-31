'''
Author: Devansh Jain (190100044)
Lab 11 1E - Comparing Fibonacci with and without Dynamic Programming
'''

import sys
import time
import multiprocessing


def fibo_slow(x):
    if x == 0:
        return 0

    if x == 1:
        return 1

    return fibo_slow(x - 1) + fibo_slow(x - 2)


def fibo_fast(x, table):
    if x == 0:
        return 0

    if x == 1:
        return 1

    if x - 1 in table:
        f1 = table[x - 1]
    else:
        f1 = fibo_fast(x - 1, table)

    if x - 2 in table:
        f2 = table[x - 2]
    else:
        f2 = fibo_fast(x - 2, table)

    table[x] = f1 + f2
    return f1 + f2


def test_slow(x):
    tic = time.perf_counter()
    print('Slow recursive function\nfib({}) = {}'.format(x, fibo_slow(x)))
    toc = time.perf_counter()
    print('Computed in {:0.4f} milliseconds\n'.format((toc - tic) * 1000))


def test_fast(x):
    tic = time.perf_counter()
    print('Fast recursion function using dynamic programming\nfib({}) = {}'.format(x, fibo_fast(x, {0: 0, 1: 1})))
    toc = time.perf_counter()
    print('Computed in {:0.4f} milliseconds\n'.format((toc - tic) * 1000))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: python 1e.py <x>')
        print('x has to be non-negative integers')
        exit(1)

    try:
        x = int(sys.argv[1])
    except Exception:
        print('Usage: python 1e.py <x>')
        print('x has to be non-negative integers')
        exit(1)

    if x < 0:
        print('Usage: python 1e.py <x>')
        print('x has to be non-negative integers')
        exit(1)

    slow = multiprocessing.Process(target=test_slow, args=(x,))
    fast = multiprocessing.Process(target=test_fast, args=(x,))

    slow.start()
    fast.start()

    slow.join(10)

    if slow.is_alive():
        print('Slow still running. Time limit 10 sec exceed')

        slow.terminate()
        # OR Kill - will work for sure, no chance for process to finish nicely however
        # slow.kill()

        slow.join()
