k=int(input())
a=input()
b=input()
n = len(a)
common = 0
for (x,y) in zip(a,b):
    common += x==y
res = min(common,k)
res += min(n-common,n-k)
print(res)
