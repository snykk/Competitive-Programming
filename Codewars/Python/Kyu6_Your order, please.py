def order(sentence):
    num = 1
    list_data = sentence.split()
    new = ''
    
    while len(new) < len(sentence):
        for i in list_data:
            for j in i:
                if j == str(num):
                    new += i + " "
                    num += 1
    return new[:-1]
