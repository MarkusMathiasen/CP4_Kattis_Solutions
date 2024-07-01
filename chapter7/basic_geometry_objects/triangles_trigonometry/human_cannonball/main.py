import math
T=int(input())
for _ in range(T):
    v0,t,x1,h1,h2=map(float, input().split())
    t = math.pi*t/180
    tim=x1/v0/math.cos(t)
    y=x1*math.tan(t)-0.5*9.81*tim**2
    print(["Not",""][h1+1 <= y and y+1 <= h2], "Safe")
