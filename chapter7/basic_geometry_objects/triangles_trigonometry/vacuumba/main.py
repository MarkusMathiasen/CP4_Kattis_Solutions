import math

n = int(input())
for _ in range(n):
    m = int(input())
    dir = math.pi/2
    x,y = 0,0
    for _ in range(m):
        ddir,dist = map(float, input().split())
        dir += ddir / 360 * 2*math.pi
        x += math.cos(dir)*dist
        y += math.sin(dir)*dist
    print(x, y)
