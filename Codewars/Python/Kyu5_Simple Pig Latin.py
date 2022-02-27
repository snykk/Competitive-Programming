def pig_it(text):
    lists = text.split()
    results = ''
    for i in lists:
        if i.isalpha():
            results += i[1:] + i[0] + 'ay' + ' '
        else:
            results += i[1:] + i[0] +  ' '
    else:
        results = results[:-1]
    return results