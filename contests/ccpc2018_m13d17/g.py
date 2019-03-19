mod=1e9+7
def cnt(x):
    return (((x*(x+1)/2*x*(x+1)/2+x*(x+1))/3-x*(x+1)*(x*2+1)/6)/2)%mod
tt=0
tt=int(input())
step=0
while(tt>0):
    s=input().split()
    n=int(s[0])
    m=int(s[1])
    tt-=1
    step+=1
    ans=int(cnt(n)*cnt(m)%mod)
    print("Case {}: {}".format(step,ans))

