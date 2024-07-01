import math
pi=math.pi
r,c=map(int,input().split())
print(100-(r*r-(r-c)**2)*pi/r/r/pi*100)
