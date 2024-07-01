import math
t=int(input())

def dist(p1, p2):
    return ((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)**0.5

for _ in range(t):
    r,n=map(int,input().split())
    A = []
    for _ in range(n):
        x,y=map(int,input().split())
        A.append((x,y))
    l = 0
    for i in range(-1, n-1):
        l += dist(A[i], A[i+1])
    rad = 2*math.pi*r
    if (l < rad):
        print("Not possible")
    else:
        print((l-rad)/l)
