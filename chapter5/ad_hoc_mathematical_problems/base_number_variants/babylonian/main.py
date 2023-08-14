for _ in range(int(input())):
	A = input().split(',')
	res = 0
	for x in A:
		res *= 60
		if x:
			res += int(x)
	print(res)

