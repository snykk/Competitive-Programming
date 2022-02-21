def square_digits(num):
    string = ''
    for x in str(num):
        string += str(int(x)**2)
    return int(string)