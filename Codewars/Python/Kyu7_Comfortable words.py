def comfortable_word(word):
    left = 'qwertasdfgzxcvb'
    right = 'yuiophjklmn'
    for i in range(len(word)-1):
        if (word[i] in left and word[i+1] in left) or (word[i] in right and word[i+1] in right):
            return False
    return True