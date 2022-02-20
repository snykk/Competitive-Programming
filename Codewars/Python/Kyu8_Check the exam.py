def check_exam(key,answer):
    score = 0
    for i in range(4):
        if key[i] == answer[i]:
            score += 4
        elif key[i] != answer[i] and answer[i] != '':
            score -= 1
    if score <0:
        score = 0
    return score
