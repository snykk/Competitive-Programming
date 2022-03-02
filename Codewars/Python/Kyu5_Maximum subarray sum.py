def max_sequence(arr):
    current_sum,max_sum = 0,0
    for i in arr:
        current_sum += i
        if current_sum <= 0:
            current_sum = 0
        elif current_sum > max_sum:
            max_sum = current_sum
    return max_sum