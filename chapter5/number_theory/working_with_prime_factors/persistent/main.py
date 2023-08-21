while True:
	n = int(input())
	if n == -1: break
	if n == 0:
		print(10)
		continue
	p = [0]*10
	for i in [2,3,5,7]:
		while n%i == 0:
			n //= i
			p[i] += 1
	if n > 1:
		print("There is no such number.")
		continue
	p[9] = p[3]//2
	p[3] %= 2
	p[8] = p[2]//3
	p[2] %= 3
	if p[2] > 0 and p[3] > 0:
		p[6] = 1
		p[2] -= 1
		p[3] -= 1
	p[4] = p[2]//2
	p[2] %= 2
	if (sum(p) == 1):
		p[1] = 1
	if (sum(p) == 0):
		p[1] = 2
	for i in range(1, 10):
		print(str(i)*p[i], end="")
	print()
