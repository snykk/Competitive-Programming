def find_it(seq):
    baru = [x for x in seq if seq.count(x)%2 !=0]
    return baru[0]
