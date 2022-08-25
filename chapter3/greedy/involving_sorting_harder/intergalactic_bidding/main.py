n, s = map(int, input().split())
def f():
	a, b = input().split()
	return int(b), a
A = [f() for _ in range(n)]
res = []
for x in reversed(sorted(A)):
	if x[0] <= s:
		s -= x[0]
		res += [x[1]]
if s > 0:
	res = []
print(len(res))
for x in res:
	print(x)
