def create_array_of_tiers(n):
    n = str(n)
    temp = []
    for i in range(1,len(n)+1):
        temp.append(n[:i])
    return temp
