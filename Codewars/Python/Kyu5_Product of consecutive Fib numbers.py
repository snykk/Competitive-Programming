def productFib(prod):
    if prod == 0:return [0,1,True]
    elif prod == 1:return [1,1,True]
    num1,num2 = 0,1
    lst = [num1, num2]
    while True:
        lst.append(num1+num2)
        temp = num2
        num2 = lst[-1]
        num1 = temp
        if (num1*num2 == prod):
            return [num1,num2,True]
        elif (num1*num2 > prod):
            return [num1,num2,False]
