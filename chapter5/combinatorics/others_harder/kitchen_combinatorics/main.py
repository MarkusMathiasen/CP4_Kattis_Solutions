r,s,m,d,n = map(int, input().split())
b = [0] + list(map(int, input().split()))
dish = [[]] + [list(map(int, input().split()))[1:] for _ in range(s+m+d)]
incompatible = set()
for i in range(n):
	x,y = map(int, input().split())
	incompatible.add((x, y))
	incompatible.add((y, x))
# Done reading input
res = 0
for i in range(1, s+1):
	for j in range(s+1, s+m+1):
		for k in range(s+m+1, s+m+d+1):
			if (i,j) in incompatible or (j, k) in incompatible or (i, k) in incompatible:
				continue
			used = [False]*(r+1)
			for x in dish[i]: used[x] = True
			for x in dish[j]: used[x] = True
			for x in dish[k]: used[x] = True
			more = 1
			for x in range(1, r+1):
				if used[x]:
					more *= b[x]
			res += more
if res > 1e18: print("too many")
else: print(res)
