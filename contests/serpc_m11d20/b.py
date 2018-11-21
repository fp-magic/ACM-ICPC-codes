import os
inn=input().split(' ')
a=int(inn[0])
b=int(inn[1])
c=int(inn[2])
n=int(inn[3])
s=0
#print(n)
if(n%2==0):
    s=n*((2+n//2)*(n//2-1)+n-2)
else:
    s=n*(1+n//2)*(n//2)
#print(s)
if(a==b or a==c or b==c):
    s=s//2
if(a==b and b==c):
    s=s//3
print(s%(1<<64))