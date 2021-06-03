def reverse(arr):
    if len(arr) == 0:
        return []
    return reverse(arr[1:]) + [arr[0]]


if __name__ == '__main__':
    l1 = [1, 0, 7, 14, 9.9]
    l2 = [1.1, 1, '123', 'hi', True]

    print(reverse(l1))
    print(reverse(l2))
