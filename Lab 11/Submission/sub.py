def sub(sub_arr, arr):
    if len(sub_arr) > len(arr):
        return False

    for n in range(len(sub_arr)):
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
