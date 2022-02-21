def elevator_distance(array):
    summ = 0
    cek = 1
    for i in range(len(array)):
        if cek < len(array):
            a = abs(array[i] - array[i+1])
            summ += a
            cek += 1
    return summ

#the smart way
def elevator_distance(array):
    return sum(abs(a - b) for a, b in zip(array, array[1:]))
