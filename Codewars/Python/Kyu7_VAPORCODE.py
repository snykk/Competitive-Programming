import string
def vaporcode(s):
    alpha = string.ascii_lowercase
    result = ""
    for char in s:
        if char != " ":
            if char.lower() in alpha:
                result += char.upper() + "  "
            else:
                result += char + "  "
    return result[:-2]
