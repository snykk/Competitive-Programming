def sequence(x):
    if x <= 9:
        return [x+1 for x in range(x)]
    lst = []
    for i in range(1,10):
        lst.append(i)
        for j in range(i*10,i*10+10):
            lst.append(j)
    result = []
    index = 1
    for i in lst:
        if i == index:
            index += 1
        result.append(i)
        if len(result) + (10 - index) == x:
            break
    for i in range(index, 10):
        result.append(i)
    return result
 