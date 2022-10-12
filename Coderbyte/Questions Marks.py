def QuestionsMarks(strParam):
    num = '0123456789'
    cek = True
    akhir = False
    a,b = 0,0
    i = 0
    strParam += 'f'
    while i < len(strParam):
        if strParam[i] in num and akhir == False:
            if a == 0:
                a = i
            else:
                a =  b
            akhir = True
        elif strParam[i] in num and akhir == True:
            b = i
            if strParam[a:b+1].count('?') < 3:
                cek = False
            akhir = False
        i += 1
    if cek == False:
        return 'false'
    else:
        return 'true'

# keep this function call here 
print(QuestionsMarks(input()))



