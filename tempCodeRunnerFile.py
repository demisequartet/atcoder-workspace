mod = int(1e9+7)


def modPow(a,n):
  if n == 0: return 1
  if n == 1: return a % mod

  if n % 2 == 1:
    return (a*modPow(a,n-1)) % mod
  
  t = modPow(a,n/2)

  return ((t*t)%mod)

n,p = map(int,input().split())

zizyo = modPow(p-2,n-1)

ans = (p-1)*zizyo % mod

print(ans)