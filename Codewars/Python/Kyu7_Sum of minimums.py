def sum_of_minimums(numbers):
    result = 0
    for i in numbers:
        result += min(i)
    return result