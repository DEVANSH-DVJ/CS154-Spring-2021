'''
Author: Devansh Jain (190100044)
Lab 11 2 - Defining Cartesian Cross Product Function
'''


def cross(arr1, arr2):
    '''
    Cartesian Cross product of arr1 and arr2
    '''

    # if either is empty then empty cartesian cross product
    if len(arr1) == 0 or len(arr2) == 0:
        return []

    # Cross product with first element of arr1 with arr2
    # followed by cross product with rest of elements of arr1 with arr2
    arr = [(arr1[0], elem) for elem in arr2] + cross(arr1[1:], arr2)

    return arr


if __name__ == '__main__':
    l1 = [1, 2, 4, 9]
    l2 = [141, '141', 42, True]

    c = cross(l1, l2)
    print('Cross product has {} terms'.format(len(c)))
    print(c)
