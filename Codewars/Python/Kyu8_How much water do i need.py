def how_much_water(water, load, clothes):
    if clothes > 2*load:
        return 'Too much clothes'
    if clothes < load:
        return 'Not enough clothes'
    else:
        return round(water*1.1**(clothes-load),2)
