def add(num1, num2):
    result = ''
    num1,num2 = str(num1),str(num2)
    if len(num1) > len(num2):
        num2 = '0'*(len(num1)-len(num2)) + num2
    else:
        num1 = '0'*(len(num2)-len(num1)) + num1
    for i,j in zip(num1,num2):
        result += str(int(i) + int(j))
    return int(result)