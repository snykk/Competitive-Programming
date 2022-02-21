import string

def longest(a1, a2):
    alpha = string.ascii_lowercase
    result = ""
    for i in alpha:
        if (i in a1 or i in a2) and i not in result:
            result += i
    
    return result