def is_prime(n):
    if n <= 1:
        return False
    else:
        cek =  True
        for i in range(2,n-1):
            if n%i == 0:
                cek = False
        if cek == True: 
            return True
        if cek == False:
            return False
