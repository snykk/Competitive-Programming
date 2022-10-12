def FirstFactorial(num):
  if num == 1:
    return 1
  else:
    return num*FirstFactorial(num-1)

# keep this function call here 
print(FirstFactorial(input()))