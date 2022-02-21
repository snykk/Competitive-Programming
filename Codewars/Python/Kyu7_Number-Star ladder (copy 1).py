def pattern(n):
    temp = '1'
    i = 1
    number = 2
    while i< n:
        string = "\n"+"1" + "*"*i + str(number)
        temp += string
        i +=1
        number += 1
    return temp
