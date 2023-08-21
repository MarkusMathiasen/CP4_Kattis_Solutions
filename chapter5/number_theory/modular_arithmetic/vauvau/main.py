a,b,c,d=map(int,input().split())
A=list(map(int,input().split()))
for x in A:
    x -= 1
    y = x%(a+b)
    res = 0
    res += y < a
    y = x%(c+d)
    res += y < c
    print(['none','one','both'][res])
