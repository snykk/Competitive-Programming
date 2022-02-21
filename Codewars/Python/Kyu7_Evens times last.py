def even_last(numbers):
    new = []
    if len(numbers) > 0:
        for i in range(len(numbers)):
            if i%2 == 0:
                new.append(numbers[i])
        result = sum(new)* numbers[-1]
        return result
    elif len(numbers) == 0:
        return 0
    
