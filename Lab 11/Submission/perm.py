'''
Author: Devansh Jain (190100044)
Lab 11 2 - Defining Permutation Function
'''


def perm(arr):
    '''
    List of all Permutations of arr
    '''

    # If empty then only one permutation - phi
    if len(arr) == 0:
        return [[]]

    # Initialize result
    res = []

    for n in range(len(arr)):
        # Permute the array excluding the nth element
        # and add the element at the start of it
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
