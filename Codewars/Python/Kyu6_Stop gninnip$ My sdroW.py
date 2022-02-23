def spin_words(sentence):
    a = sentence.split()
    result = ''
    for i in a:
        if len(i) >= 5:
            result += i[::-1] + " "
        else:
            result += i + " "
    return result[:-1]
