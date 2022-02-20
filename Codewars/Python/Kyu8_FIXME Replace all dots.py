def replace_dots(str):
    results = ''
    for i in str:
        if i == '.':
            i = '-'
            results += i
        else:
            results += i
    return results