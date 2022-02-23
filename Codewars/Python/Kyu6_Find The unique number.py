def find_uniq(arr):
    arr.sort()
    return arr[-1] if arr.count(arr[-1]) == 1 else arr[0]