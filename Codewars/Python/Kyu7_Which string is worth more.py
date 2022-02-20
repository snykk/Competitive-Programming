def highest_value(a, b):
    value1 = 0
    value2 = 0
    for i in range(len(a)):
        value1 += ord(a[i])
        value2 += ord(b[i])
        
    if value1 < value2:
        return b
    else:
        return a