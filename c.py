def printList(ans):
  for i in ans:
    for j in i:
      print(j,end='')
    print('\n')



calc = list(range(1,4)) # 1 2 3 

n = 2

ans=[]

for bit in range(2**n):
  print(bit)
  copy = calc
  cnt = 0
  for i in range(n):
    if ((bit >> i) & 1):
      copy.insert(i+cnt+1,'+')
      cnt += 1
  ans.append(copy)

printList(ans)
