def LongestWord(sen):
  abj = ' abcdefghijklmnopqrstuvwxyz'
  baru = ''
  for i in sen:
    if i in abj:
      baru += i
  lst = baru.split()
  panjang_maks = 0
  indeks = 0
  for i in range(len(lst)):
    if len(lst[i]) > panjang_maks:
      panjang_maks = len(lst[i])
      indeks = i
  return lst[indeks]

# keep this function call here 
print(LongestWord(input()))