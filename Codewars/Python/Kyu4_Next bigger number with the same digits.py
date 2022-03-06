def next_bigger(n):
    loc = 0
    lstNum = [x for x in str(n)]
    for i in range(len(lstNum)-1,0,-1):
        if lstNum[i] > lstNum[i-1]:
            temp = lstNum[i]
            locZ = i
            for z in range(i,len(lstNum)):
                if lstNum[z] < temp and lstNum[z] > lstNum[i-1]:
                    temp = lstNum[z]
                    locZ = z
            lstNum[i-1],lstNum[locZ] = lstNum[locZ], lstNum[i-1]
            loc = i
            break
    else:
        return -1
    #bubble short implementation
    for i in range(loc,len(lstNum)):
        for j in range(loc,len(lstNum)-1):
            if lstNum[j] > lstNum[j+1]:
                lstNum[j],lstNum[j+1] = lstNum[j+1],lstNum[j]
    return int("".join(lstNum))