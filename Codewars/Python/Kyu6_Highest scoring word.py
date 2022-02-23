import string
def high(x):
    list_data = x.split()
    current_sum = 0
    max_sum = 0
    char = ''
    list_string = string.ascii_lowercase
    for i in list_data:
        for j in i:
            for k in range(len(list_string)):
                if j == list_string[k]:
                    current_sum += k + 1
        if current_sum > max_sum:
            max_sum = current_sum
            char = i
        current_sum = 0
    return char
