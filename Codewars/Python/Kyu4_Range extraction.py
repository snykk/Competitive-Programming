def solution(args):
    result = ""
    list_temporary = [args[0]]
    for i in range(1, len(args)):
        if args[i] - list_temporary[-1] == 1:
            list_temporary.append(args[i])
        elif len(list_temporary) >= 3 and args[i] - list_temporary[-1] != 1:
            result += f"{list_temporary[0]}-{list_temporary[-1]},"
            list_temporary = [args[i]]
        elif len(list_temporary) == 2 and args[i] - list_temporary[-1] != 1:
            result += f"{list_temporary[0]},{list_temporary[1]},"
            list_temporary = [args[i]]
        else:
            result += f"{list_temporary[0]},"
            list_temporary = [args[i]]          
    if len(list_temporary) > 2:
        result += f"{list_temporary[0]}-{list_temporary[-1]}"
    elif len(list_temporary) == 2:
        result += f"{list_temporary[0]},{list_temporary[-1]}"
    else:
        result += str(list_temporary[0])
    return result
