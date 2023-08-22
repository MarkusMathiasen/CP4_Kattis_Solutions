n = int(input())
C = [1]*(n+1)
for i in range(n):
	C[i+1] = C[i]*(4*i+2)//(i+2)

res = 0
for i in range(n+1):
	res += C[i]*C[n-i]

print(res)
