while True:
    a,b,c=sorted(map(int,input().split()))
    if a==b==c==0:exit(0)
    print(['wrong','right'][a*a+b*b==c*c])
