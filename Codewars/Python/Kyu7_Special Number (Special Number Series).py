# original name of kyu: Kyu7_Special Number (Special Number Series #5)

def special_number(number):
    cek = True
    for i in str(number):
        if i not in '012345':
            cek = False
            break
    if cek:
        return "Special!!"
    else:
        return "NOT!!"