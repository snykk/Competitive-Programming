def small_enough(array, limit):
    cek = True
    for i in array:
        if i > limit:
            cek = False
            break
    return cek