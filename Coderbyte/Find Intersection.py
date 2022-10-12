def FindIntersection(strArr):
    lst_awal = strArr[0].split(', ')
    lst_akhir = strArr[1].split(', ')
    lst = []
    for i  in lst_awal:
        if i in lst_akhir:
            lst.append(i)
    string = ''
    for i in range(len(lst)):
        string += lst[i]
        if i+1 != len(lst):
            string += ','
    return string if len(string) > 0 else 'false'

# keep this function call here 
print(FindIntersection(input()))