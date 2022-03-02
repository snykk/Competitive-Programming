def guess_gifts(wishlist, presents): 
    lst = []
    sub = ['name', 'size', 'clatters', 'weight']
    for i in presents:
        for j in wishlist:
            if i[sub[1]] == j[sub[1]] and i[sub[2]] == j[sub[2]] and i[sub[3]] == j[sub[3]] and j[sub[0]] not in lst:
                lst.append(j[sub[0]])
    return lst
