def move_zeros(array):
    result = []
    for i in range(len(array)):
        if array[i] != 0 or array[i] is bool(array[i]):
            result.append(array[i])
    for i in range(len(array)):
        if array[i] == 0 and array[i] is not bool(array[i]):
            result.append(array[i])
    print(result)
