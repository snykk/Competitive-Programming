def sum_digits(number):
    counter = 0
    number = abs(number)
    for i in str(number):
    	counter += int(i)
    return counter