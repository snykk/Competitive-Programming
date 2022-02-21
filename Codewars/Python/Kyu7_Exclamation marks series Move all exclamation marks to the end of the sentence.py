def remove(s):
    simbol = []
    clear = []
    for i in s:
        if i =='!':
            simbol.append(i)
        else:
            clear.append(i)
    return ''.join(clear+simbol)