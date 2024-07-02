#read three points in the plane as input
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
#compute and print the area of the triangle
def area(x1, y1, x2, y2, x3, y3):
    #compute the area of the triangle
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2)

#print area of triangle
print(area(x1, y1, x2, y2, x3, y3))

#function to check if point is inside the triangle
def isInside(x1, y1, x2, y2, x3, y3, x, y):
    # Compute area of triangle ABC
    A = area(x1, y1, x2, y2, x3, y3)
    # Compute area of triangle PBC
    A1 = area (x, y, x2, y2, x3, y3)
    # Compute area of triangle PAC
    A2 = area (x1, y1, x, y, x3, y3)
    # Compute area of triangle PAB
    A3 = area (x1, y1, x2, y2, x, y)
    # Check if sum of A1, A2 and A3 is same as A
    if(A == A1 + A2 + A3):
        return True
    else:
        return False
cnt = 0
#read the number of points
n = int(input())
#read the points
for i in range(n):
    x, y = map(int, input().split())
    #check if the point is inside the triangle
    if(isInside(x1, y1, x2, y2, x3, y3, x, y)):
        cnt += 1
#print the number of points inside the triangle
print(cnt)
