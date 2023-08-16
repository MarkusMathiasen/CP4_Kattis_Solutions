a,b=map(int,input().split())
while a or b:
    print(a//b, a%b, "/", b)
    a,b=map(int,input().split())
