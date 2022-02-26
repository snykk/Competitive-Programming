def longest_consec(strarr, k):
    i = 0
    cek = 0
    result = ''
    while i < len(strarr) + 1 - k:
        string = ''
        j = i
        while j < i + k:
            string += strarr[j]
            j += 1
        if len(string) > cek:
            result = string
            cek = len(string)
        i += 1 
    return result
