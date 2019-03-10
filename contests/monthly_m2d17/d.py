f=[]
f.append(1)
p=100000007700000049
t=1
for i in range(1,200005):
    t=(t*i)
    f.append(t)
print(1);
def fast(a,n):
    if(n==0):
        return 1
    if(n%2):
        return a*fast(a,n-1)%p
    tmp=fast(a,n/2)
    return tmp*tmp%p

def C(n,m):
    if(n==m or m==0):
        return 1
    return ((f[n]*fast(f[m],p-2)%p)*fast(f[n-m],p-2))%p;
print(C(5,2))