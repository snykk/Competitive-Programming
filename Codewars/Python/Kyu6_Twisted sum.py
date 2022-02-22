def compute_sum(n):
    a = 1
    string = ''
    summ = 0
    while a <= n:
        string = str(a)
        for i in string:
            summ += int(i)
        a += 1        
    return summ
