import sys


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

    print('Slow recursive function')
    print('fib({}) = {}'.format(x, fibo_slow(x)))

    print('Fast recursion function using dynamic programming')
    print('fib({}) = {}'.format(x, fibo_fast(x, {0: 0, 1: 1})))
