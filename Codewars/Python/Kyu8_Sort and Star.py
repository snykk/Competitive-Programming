def two_sort(array):
    result = ''
    array.sort()
    for i in range(len(array[0])):
        result += array[0][i]
        if i < len(array[0]) -1 :
            result += '***'
            
    return result