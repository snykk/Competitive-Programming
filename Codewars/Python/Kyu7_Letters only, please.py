def remove_chars(s):
    letters = ' abcdefghijklmnopqrstuvwxyz'
    string = ''
    for i in s:
        if i.lower() in letters:
            string += i
    return string