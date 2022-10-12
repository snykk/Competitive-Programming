def unique_in_order(iterable):
    if len(iterable) == 0: return [] 
    result = [iterable[0]]
    for i in iterable[1:]:
        if i != result[-1]:
            result.append(i)
    return result