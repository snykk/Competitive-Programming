import string
def is_pangram(s):
    alpha = string.ascii_lowercase
    for i in alpha:
        if i not in s.lower():
            return False
    return True