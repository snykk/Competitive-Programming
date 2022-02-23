def inside_out(st):
    st += " "
    result = ""
    word = ""
    for i in st:
        if i != " ":
            word += i
        else:
            div = len(word)//2-1
            result += word[div::-1]
            if len(word)%2 != 0 and len(word) != 1:
                result += word[div+1]
                result += word[:div+1:-1]
            elif len(word)%2 == 0:
                result += word[:div:-1]
            word = ""
            result += i
    return result[:-1]
