def prev_mult_of_three(n):
    a = 10
    if n%3 == 0:
        return n
    while n//a != 0:
        if (n//a)%3 == 0:
            return n//a
        else:
            a *= 10
    return None
