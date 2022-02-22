def amaro_plan(pirate):
    num_list = []
    if pirate%2 == 0:
        num = (pirate-2)//2
        stok = 20*pirate - num
        num_list.append(stok)
    if pirate%2 != 0:
        stok = 20*pirate-pirate//2
        num_list.append(stok)
    for i in range(pirate-1):
        if i%2 == 0:
            num_list.append(0)
        elif i%2 ==1:
            num_list.append(1)
    return num_list
