a=0
b=1
for i in range(10000):
    c=a+b
    a=b
    b=c
    print(i+2, len(str(c)))