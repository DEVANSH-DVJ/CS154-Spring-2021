'''
Author: Devansh Jain (190100044)
Lab 11 2 - Defining Reverse Function
'''


def reverse(arr):
    '''
    Reverse arr
    '''

    # If empty, nothing to reverse
    if len(arr) == 0:
        return []

    # Reverse the array excluding the fist element
    # and then add first element to the back
    return reverse(arr[1:]) + [arr[0]]


if __name__ == '__main__':
    l1 = [1, 0, 7, 14, 9.9]
    l2 = [1.1, 1, '123', 'hi', True]

    print(reverse(l1))
    print(reverse(l2))
