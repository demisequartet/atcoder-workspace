n = int(input())

inf = 999999999999

ans = inf

for i in range(n):
  a,p,x = map(int,input().split())

  if x - a > 0:
    ans = min(ans,p)


print(-1 if ans == inf else ans)

