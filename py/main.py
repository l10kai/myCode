lim=450000
isp=[True]*(lim+1);p=[];isp[1]=False
for i in range(2,lim+1):
    if isp[i]:
        p.append(i)
    x=0

    while x<len(p) and i*p[x]<=lim:
        isp[i*p[x]]=False
        if i%p[x]==0:break
        x+=1

m,n = map(int,input().split())

pp = []
for x in p:
    if (m <= x <= n) and x!=2 : pp.append(x)
    if(x > n): break


from itertools import combinations
if m>2:print(0);exit()

cc=0;
for li in combinations(pp,2):
    p=2
    q,r=li
    if isp[p*q+r] and isp[p*r+q] and isp[q*r+p]:
        cc+=1

print(cc)


    