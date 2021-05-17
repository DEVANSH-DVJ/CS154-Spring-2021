# Author: Devansh Jain (190100044)
# Lab 10 - Word Frequency

import sys  # For command line arguments


def count(arr, dic):
    for w in arr:
        dic[w] = dic.get(w, 0) + 1
    return dic


print('Method 1: using sets')
print1 = lambda arr: [print(e, arr.count(e)) for e in set(arr)]
print1(open(sys.argv[1], 'r').read().split())

print('\nMethod 2: using dicts')
print2 = lambda dic: [print(k, v) for k, v in dic.items()]
print2(count(open(sys.argv[1], 'r').read().split(), {}))
