def get_prime(lim):
    isp=[True]*(lim+1);p=[];isp[1]=False
    for i in range(2,lim+1):
        if isp[i]:
            p.append(i)
        x=0
        while x<len(p) and i*p[x]<=lim:
            isp[i*p[x]]=False
            if i%p[x]==0:break
            x+=1
    return p

m,n = map(int,input().split())
p = get_prime(1e6)
pp = []
for x in p:
    if x >= m : pp.append(x)

from itertools import combinations




    