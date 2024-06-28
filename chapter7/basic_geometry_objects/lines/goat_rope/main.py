import math
x,y,x1,y1,x2,y2 = map(int, input().split())
def dist(a, b):
    return math.sqrt((x-a)**2+(y-b)**2)
if x1 <= x and x <= x2:
    print(min(abs(y-y1), abs(y-y2)))
elif y1 <= y and y <= y2:
    print(min(abs(x-x1), abs(x-x2)))
else:
    print(min(dist(x1, y1), dist(x1, y2), dist(x2, y1), dist(x2, y2)))
