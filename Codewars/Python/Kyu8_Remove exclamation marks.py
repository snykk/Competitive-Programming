def remove_exclamation_marks(s):
    exclamation = "!"
    new = ''
    for i in s:
        if i != exclamation:
            new += i
    return new
