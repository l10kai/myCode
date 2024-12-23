import sys, math, bisect, heapq,random
input = lambda: sys.stdin.readline()
from collections import deque
rd=random.randint(10**9,2*10**9)

t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]

    p=set();a.sort();b.sort()
    for i in range(n):
        p.add(rd^a[i])
        p.add(rd^b[i])

    ans=0
    for x in p:
        x^=rd
        ia=bisect.bisect_left(a,x)
        ib=bisect.bisect_left(b,x)
        #if ia==n or a[ia]==x:ia-=1
        #if ib==n or b[ib]==x:ib-=1
        ia-=1;ib-=1
        #print(x,ia,ib,a,b,ia-ib,k)
        unSatis=(n-ib-1)-(n-ia-1)
        if unSatis>k:continue
        ans=max(ans,(n-ib-1)*x)

    print(ans)
