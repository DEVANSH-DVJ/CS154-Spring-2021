def sub(sub_arr, arr):
    if len(sub_arr) > len(arr):
        return False

    for n in range(len(sub_arr)):
        if sub_arr[n] != arr[n] or type(sub_arr[n]) is not type(arr[n]):
            return sub(sub_arr, arr[1:])

    return True
