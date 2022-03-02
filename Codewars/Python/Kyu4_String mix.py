def sorting_lst(karakter,angka, pos):
    lst_k,lst_a,lst = [],[],[]
    i = 0
    while i < len(karakter):
        if pos == angka[i]:
            lst_k.append(karakter[i])
            lst_a.append(angka[i]) 
        i += 1
    lst.append(lst_k)
    lst.append(lst_a)
    return lst

def mix(s1, s2):
    s1.lower()
    s2.lower()
    lst_a,lst_b = [], []
    karakter = []
    angka = []    
    abj = "abcdefghijklmnopqrstuvwxyz"
    for i, j in zip(abj, abj):
        check_point = ''
        if i not in lst_a and i != " ":
            n1 = s1.count(i)
            n2 = s2.count(i)
            lst_a.append(i)
            if i not in karakter and n1 > 1 or n2 > 1:
                if n1  == n2:
                    check_point =  '='
                elif n1 > n2:
                    check_point = '1'
            angka.append(check_point)
            karakter.append(i*n1)
                
        if j not in lst_b and j != " ":
            n1 = s1.count(j)
            n2 = s2.count(j)
            lst_b.append(j)
            if j not in karakter and n1 > 1 or n2 > 1:
                if n1 < n2:
                    check_point = '2'
                    angka.append(check_point)
                    karakter.append(j*n2)
#     print(karakter)
#     print(angka)
    karakter_new, angka_new = [],[]
    lst = []
    karakter_new.append(sorting_lst(karakter,angka,'1')[0])
    angka_new.append(sorting_lst(karakter,angka,'1')[1])
    karakter_new.append(sorting_lst(karakter,angka,'2')[0])
    angka_new.append(sorting_lst(karakter,angka,'2')[1])
    karakter_new.append(sorting_lst(karakter,angka,'=')[0])
    angka_new.append(sorting_lst(karakter,angka,'=')[1])
    karakter, angka = [],[]
    for i in karakter_new:
        for j in i:
            karakter.append(j)
    for i in angka_new:
        for j in i:
            angka.append(j)
    karakter_new = []
    angka_new = []
#     print(karakter)
#     print(angka)
    length = len(karakter)
    while len(karakter_new) < length:
        cons = 0
        indeks = 0
        cek = True
        for i in range(len(karakter)):
            if len(karakter[i]) > cons:
                cons = len(karakter[i])
                indeks = i
                cek = True
        karakter_new.append(karakter[indeks])
        angka_new.append(angka[indeks])
        karakter.pop(indeks)
        angka.pop(indeks)
    string_hasil = ''
    for i in range(len(karakter_new)):
        string_hasil += angka_new[i] + ":" + karakter_new[i]
        if i+1 != len(karakter_new):
            string_hasil += "/"
#     print("barrrr")
    return string_hasil

# "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg"
# noob solution i've ever solve :v