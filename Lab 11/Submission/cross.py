def cross(arr1, arr2):
    if len(arr1) == 0 or len(arr2) == 0:
        return []

    arr = [(arr1[0], elem) for elem in arr2] + cross(arr1[1:], arr2)

    return arr


if __name__ == '__main__':
    l1 = [1, 2, 4, 9]
    l2 = [141, '141', 42, True]

    c = cross(l1, l2)
    print('Cross product has {} terms'.format(len(c)))
    print(c)
