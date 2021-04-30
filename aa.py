n,k = map(int,input().split())
a = list(map(int,input().split()))

prev = 1
now = 1

for i in range(n):
  if i <= k - 1:
    now *= a[i]
  else:
    prev = now
    now /= a[i-k]
    now *= a[i]
    print("Yes" if now > prev else "No")