def perm(arr):
    if len(arr) == 0:
        return [[]]

    res = []
    for n in range(len(arr)):
        value = arr.pop(n)
        res += [[value] + perm_elem for perm_elem in perm(arr)]
        arr.insert(n, value)

    return res


if __name__ == '__main__':
    l1 = [1, 2, 'hi', True]
    l2 = [1, 2, 3]

    p1 = perm(l1)
    p2 = perm(l2)

    print('Number of permutation of {} are {}'.format(l1, len(p1)))
    print(p1)

    print('Number of permutation of {} are {}'.format(l2, len(p2)))
    print(p2)
