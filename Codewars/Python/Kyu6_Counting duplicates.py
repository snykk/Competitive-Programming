def duplicate_count(text):
    result = ''
    cek = ''
    for i in text:
        cek += i.lower()
    for i in cek:
        if cek.count(i) > 1 and i not in result:
            result += i  
    return len(result)

