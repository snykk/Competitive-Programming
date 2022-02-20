def correct(s):
    result = ''
    for i in s:
        if i == '0':
            i = 'O'
        elif i == '5':
            i = 'S'
        elif i == '1':
            i = 'I'
        result += i
    return result