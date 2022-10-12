def even_last(numbers):
    baru = []
    if len(numbers) > 0:
        for i in range(len(numbers)):
            if i%2 == 0:
                baru.append(numbers[i])
        hasil = sum(baru)* numbers[-1]
        return hasil
    elif len(numbers) == 0:
        return 0
    
