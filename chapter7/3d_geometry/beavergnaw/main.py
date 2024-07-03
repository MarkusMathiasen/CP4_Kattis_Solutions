import math
sqrt=math.sqrt
pi=math.pi
def get_V(D, d):
    V_big = (D/2)**2*pi*D
    V_small = (d/2)**2*pi*d
    V_cone = (D/2)**2*pi*(D/2)/3
    V_cone2 = V_cone - (d/2)**2*pi*(d/2)/3
    return V_big-V_small - 2*V_cone2

eps=1e-8
D,V=map(int, input().split())
while D and V:
    low,high=0,D
    while low+eps<high and low*(1+eps)<high:
        mid = (low+high)/2
        if get_V(D, mid) < V:
            high = mid
        else:
            low = mid
    print(low)
    D,V=map(int, input().split())
