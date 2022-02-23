def solution(s):
    result = []
    if len(s)%2 == 0:
        for i in range(len(s)):
            if i%2 == 0:
                result.append(s[i:i+2])
    elif len(s)%2 != 0:
        for i in range(len(s[:-1])):
            if i%2 ==0:
                result.append(s[i:i+2])
        res = str(s[-1:]) + "_"
        result.append(akhir)
    return result
