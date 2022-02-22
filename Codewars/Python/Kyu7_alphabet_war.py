def alphabet_war(fight):
    dictt = {'w':4,'p':3,'b':2,'s':1,'m':-4,'q':-3,'d':-2,'z':-1}
    const = ['w','p','b','s','m','q','d','z']
    summ = 0
    for i  in fight:
        for j in const:
            if i == j:
                summ += dictt[j]
    if summ == 0:
        return "Let's fight again!"
    elif summ > 0:
        return "Left side wins!"
    else:
        return "Right side wins!"