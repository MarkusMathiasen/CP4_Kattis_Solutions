C = float(input())
L = int(input())
res = 0
for i in range(L):
	a,b=map(float,input().split())
	res += C*a*b
print(res)
