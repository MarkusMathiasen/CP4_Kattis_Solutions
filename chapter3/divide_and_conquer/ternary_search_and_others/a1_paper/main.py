n = int(input())
A = list(map(int, input().split()))
h = [(2**(-3/4), 2**(-5/4))]
for i in range(n):
    h += [(h[-1][1], h[-1][0]/2)]

res = 0
tomake = 2
siz = 0
while siz < n-1 and tomake > 0:
    res += (tomake//2)*h[siz][0]
    tomake -= A[siz]
    tomake *= 2
    siz += 1

if tomake > 0:
    print("impossible")
else:
    print(res)
