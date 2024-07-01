import math
N=int(input())
for _ in range(N):n,l,d,g=map(int,input().split());print(n*math.tan(math.pi*(n-2)/(2*n))*l*l/4+n*l*d*g+d*g*d*g*math.pi)
