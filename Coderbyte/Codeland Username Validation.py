def CodelandUsernameValidation(strParam):
  data = 'abcdefghijklmnopqrstuvwxyz_0123456789'
  cek = True
  sp = strParam
  if len(sp) < 4 or len(sp) > 25 or sp[0] not in data[0:26] or sp[-1] == data[26]:
    cek = False
  for i in sp:
    if i not in data:
      cek = False
  return cek

# keep this function call here 
print(CodelandUsernameValidation(input()))