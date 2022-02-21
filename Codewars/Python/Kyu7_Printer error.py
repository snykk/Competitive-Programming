import string

def printer_error(s):
    a_to_m = string.ascii_lowercase[:13]
    sum = 0
    for i in s:
        if i not in a_to_m:
            sum += 1
    return str(sum) + '/' + str(len(s))