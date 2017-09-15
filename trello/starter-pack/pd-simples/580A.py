input()
a = list(map(int,input().split()))
ans = -1
cur = 1
for i in range(len(a)-1) :
    if a[i] > a[i+1] :
        ans = max(ans,cur)
        cur = 1
        continue
    cur += 1
ans = max(ans,cur)

print('{}'.format(ans if ans != -1 else len(a)))
