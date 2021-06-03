'''
Author: Devansh Jain (190100044)
Lab 11 2 - Defining Sublist Function
'''


def sub(sub_arr, arr):
    '''
    Whether sub_arr is a sub-array of arr
    '''

    # If length of sub_arr is more, not possible
    if len(sub_arr) > len(arr):
        return False

    # Start checking from first element of arr
    for n in range(len(sub_arr)):
        # If elements (type and value) don't match
        # then start from second element of arr
        if sub_arr[n] != arr[n] or type(sub_arr[n]) is not type(arr[n]):
            return sub(sub_arr, arr[1:])

    return True


if __name__ == '__main__':
    l1 = [1, 0, 7, 14, 9.9]
    l2 = [1.1, 1, '123', 'hi', True]
    l3 = [1, False]
    l4 = [1, 0]

    print(sub(l2, l1))
    print(sub(l3, l1))
    print(sub(l4, l1))
