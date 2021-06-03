def perm(arr):
    if len(arr) == 0:
        return [[]]

    res = []
    for n in range(len(arr)):
        value = arr.pop(n)
        res += [[value] + perm_elem for perm_elem in perm(arr)]
        arr.insert(n, value)

    return res
