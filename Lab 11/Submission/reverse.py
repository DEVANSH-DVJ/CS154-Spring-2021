def reverse(arr):
    if len(arr) == 0:
        return []
    return reverse(arr[1:]) + [arr[0]]
