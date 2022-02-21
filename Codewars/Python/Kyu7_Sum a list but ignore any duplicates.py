def sum_no_duplicates(isi):
    return sum(list([x for x in isi if isi.count(x) ==1]))
