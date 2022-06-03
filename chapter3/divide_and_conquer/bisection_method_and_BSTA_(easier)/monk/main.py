a, d, = map(int, input().split())
asc = [list(map(int, input().split())) for _ in range(a)]
des = [list(map(int, input().split())) for _ in range(d)]
height = sum([x[0] for x in asc])

def calcHeight(segs, t):
    res = 0
    for seg in segs:
        if t > seg[1]:
            res += seg[0]
            t -= seg[1]
        else:
            return res + t * seg[0] / seg[1]
    return res

low = 0
high = 5000000
while low < high - 1e-7:
    mid = (low + high)/2
    h1 = calcHeight(asc, mid)
    h2 = height - calcHeight(des, mid)
    if h1 < h2:
        low = mid
    else:
        high = mid
print(low)
