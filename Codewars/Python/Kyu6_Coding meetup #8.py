def all_continents(lst): 
    daftar_regional = []
    for i in range(len(lst)):
        if lst[i]["continent"] not in daftar_regional and lst[i]["continent"][0].isupper():
            daftar_regional.append(lst[i]["continent"])
    if len(daftar_regional) == 5:
        return True
    else:
        return False
# way the guy like einstein
def all_continents(lst): 
    return len(set(x["continent"] for x in lst)) == 5
