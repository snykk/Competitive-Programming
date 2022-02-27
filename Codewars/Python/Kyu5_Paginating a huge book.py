def page_digits(pages):
    counter = 9
    kali = 1
    summ = 0
    while pages:
        if pages - counter >= 0:
            summ += counter*kali
            kali += 1
            pages -= counter
            counter *= 10
        elif pages > 0:
            summ += pages*kali
            break
    return summ