def wrap(height, width, length):
    arr = [height, width, length]
    arr.sort()
    return 20 + sum(arr[x]*4 if x==0 else arr[x]*2  for x in range(len(arr)))
    