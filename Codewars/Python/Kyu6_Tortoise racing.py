def race(v1, v2, g):
    if v1 > v2: return None
    s2 = v2*g/(v2-v1)
    t2 = s2/(v2/3600)
    hour = t2/3600
    t2 = t2%3600
    minute = t2/60
    t2 = t2%60;
    return [int(hour), int(minute), int(t2)]
