import sys
f = lambda x: [print(e, x.count(e)) for e in set(x)]
f(open(sys.argv[1], 'r').read().split())
