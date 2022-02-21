def gimme(variabel):
    i = 0
    if variabel[i] < variabel[i+1] and variabel[i] > variabel[i+2] or variabel[i] < variabel[i+2] and variabel[i] > variabel[i+1] :
        return i
    if variabel[i+1] < variabel[i] and  variabel[i+1] > variabel[i+2] or variabel[i+1] < variabel[i+2] and variabel[i+1] > variabel[i]:
        return i+1
    if variabel[i+2] < variabel[i] and variabel[i+2] > variabel[i+1] or variabel[i+2] < variabel[i+1] and variabel[i+2] > variabel[i]:
        return i+2
    
