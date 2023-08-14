A = '0123456789abcdef'

def to_b(s,b):
	if all([k in A[:b] for k in s]):
		return int(s,b)
	return 0

T = int(input())
for _ in range(T):
	t,n=input().split()
	print(t, to_b(n,8), to_b(n,10), to_b(n, 16))
