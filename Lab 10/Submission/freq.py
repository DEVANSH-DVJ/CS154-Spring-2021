import sys


def count(x, dic):
    for w in x:
        dic[w] = dic.get(w, 0) + 1
    return dic


print('Method 1: using sets')
print1 = lambda x: [print(e, x.count(e)) for e in set(x)]
print1(open(sys.argv[1], 'r').read().split())

print('\nMethod 2: using dicts')
print2 = lambda x: [print(k, v) for k, v in x.items()]
print2(count(open(sys.argv[1], 'r').read().split(), {}))
