def solution(string,markers):
    result = ""
    each_line = string.split("\n")
    for i in each_line:
        for j in range(len(i)):
            if i[j] in markers:
                break
            result += i[j]
        result += "\n"
    result = result.replace(" \n", "\n")
    return result[:-1]