def special_number(number):
    cek = True
    for i in str(number):
        if i not in '012345':
            cek = False
    if cek:
        return "Special!!"
    else:
        return "NOT!!"