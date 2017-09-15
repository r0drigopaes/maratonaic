# https://www.urionlinejudge.com.br/judge/en/problems/view/1025
def bs(beg,end,x,minimo) :
    global a
    if beg == end :
        if a[beg] == x:
            return beg
        if a[minimo] != -1:
            return minimo
        return -1
    mid = (beg+end)//2
    if a[mid] < x :
        nbeg = mid+1 if mid+1 <= end else end
        return bs(nbeg,end,x,minimo)
    elif a[mid] > x :
        nend = mid-1 if mid-1 >= beg else beg
        return bs(beg,nend,x,minimo)
    else :
        minimo = mid
        nend = mid-1 if mid-1 >= beg else beg
        return bs(beg,nend,x,minimo)

t = 1
while True :
    m,c = map(int,input().split())
    if m==0 and c==0 :
        exit()
    a = list()
    for _ in range(m) :
        a.append(int(input()))
    a.sort()
    print('CASE# {}:'.format(t))
    for _ in range(c) :
        qq = int(input())
        ans = bs(0,m-1,qq,-1)
        if ans != -1 :
            print('{} found at {}'.format(qq,ans+1))
        else :
            print('{} not found'.format(qq))
    t+=1
