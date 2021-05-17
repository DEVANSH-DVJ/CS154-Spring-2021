import sys


print('Method 1: using sets')
print1 = lambda x: [print(e, x.count(e)) for e in set(x)]
print1(open(sys.argv[1], 'r').read().split())
