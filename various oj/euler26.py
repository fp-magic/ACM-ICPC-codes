print(10**100//62)
'''
s=9
f={}
for i in range(1,1000):
    for j in range(1,1001):
        if(j>s):
            break
        if(j in f):
            continue
        if(s%j==0):
            f[j]=1
            print(i,j,10**200//j)
        s=s*10+9
'''