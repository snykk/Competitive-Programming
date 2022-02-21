def remove_consecutive_duplicates(s):
    lst = s.split(" ")
    result_list = [lst[0]]
    for i in lst[1:]:
        if result_list[-1] != i:
            result_list.append(i)
    return " ".join(result_list)
