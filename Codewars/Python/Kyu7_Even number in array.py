def even_numbers(arr,n):
    new = []
    new_af = []
    sum_n = 0
    for i in arr[::-1]:
        if i%2 == 0 and sum_n < n:
            new.append(i)
            sum_n += 1
    for a in new[::-1]:
        new_af.append(a)
    return new_af
