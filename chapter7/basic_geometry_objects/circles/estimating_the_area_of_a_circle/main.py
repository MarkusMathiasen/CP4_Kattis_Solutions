import math
r,m,c=map(float, input().split())
while r+m+c > 0:
    print(r*r*math.pi, c*4*r*r/m)
    r,m,c=map(float, input().split())
