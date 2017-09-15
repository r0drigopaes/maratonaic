n = int(input())
a = list(map(int,input().split()))
q = int(input())
a.sort()
ans = 0
def bsl(beg,end,x,upper) :
    global a
    while beg <= end :
        mid = (beg+end)//2
        if a[mid] <= x :
            upper = mid
            beg = mid+1
        else :
            end = mid -1
    return upper+1
for _ in range(q):
    qq = int(input())
    ans = bsl(0,n-1,qq,0) if qq >= a[0] else 0
    print(ans)
