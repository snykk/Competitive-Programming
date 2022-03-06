def time(seconds):
    ls = []
    ls.append(seconds//3600)
    seconds %= 3600
    ls.append(seconds//60)
    seconds %= 60
    ls.append(seconds)
    return ls

def years(seconds):
    ls = []
    ls.append(seconds//31536000)
    seconds %= 31536000
    ls.append(seconds//86400)
    seconds %= 86400
    return ls, seconds

def format_duration(seconds):
    if seconds == 0:
        return 'now'
    string = ''
    formatt = ['year','day','hour','minute','second']
    ls, seconds = years(seconds)
    ls.extend(time(seconds))
    for i,j in zip(ls,formatt):
        if i == 0:
            continue
        if i > 1:
            string += f"{i} {j}s, "
        else:
            string += f"{i} {j}, "
    if len(string) > 12:
        locate = string[-3::-1].index(',')
        div = -(locate + 3)
        front = string[:div]
        back = string[div+2:-2]
        return front + ' and ' + back
    else:
        return string[:-2]
