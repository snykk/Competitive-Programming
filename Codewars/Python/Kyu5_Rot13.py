import string

def rot13(message):
    alpha = string.ascii_uppercase
    result = ""
    for char in message:
        if char in alpha.lower():
            result += alpha[(alpha.lower().index(char) +13) % 26].lower()
        elif char in alpha:
            result += alpha[(alpha.index(char) +13) % 26]
        else:
            result += char
    return result
    