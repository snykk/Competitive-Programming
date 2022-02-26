def valid_parentheses(string):
    open_bracket,closed_bracket = 0,0
    if string == '':
        return True
    elif string[0] == ")" or string[-1] == "(":return False
    for i in string:
        if closed_bracket > open_bracket:return False
        if i == "(":
            open_bracket += 1
        elif i ==")":
            closed_bracket += 1
    if open_bracket == closed_bracket:return True
    else:return False