def cross(arr1, arr2):
    if len(arr1) == 0 or len(arr2) == 0:
        return []

    arr = [(arr1[0], elem) for elem in arr2]

    arr += cross(arr1[1:], arr2)

    return arr
