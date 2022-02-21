def solve(a,b):
    result = ""
    for i in a:
        if i not in b:
            result += i
    for i in b:
        if i not in a:
            result += i
    return result