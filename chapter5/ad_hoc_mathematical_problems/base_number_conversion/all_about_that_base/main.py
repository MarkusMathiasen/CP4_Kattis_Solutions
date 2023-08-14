A="0123456789abcdefghijklmnopqrstuvwxyz0"

def is_b(s, b):
	return all([k in A[:b] for k in s])

def is_1(s):
	return all([k=='1' for k in s])

def check(a, b, c, op):
	if op == '+': return a + b == c
	if op == '-': return a - b == c
	if op == '*': return a * b == c
	if op == '/': return a // b == c and a%b == 0

for _ in range(int(input())):
	a, op, b, eq, c = input().split()
	res = []
	if (is_1(a) and is_1(b) and is_1(c)):
		na = len(a)
		nb = len(b)
		nc = len(c)
		if (check(na, nb, nc, op)):
			res.append("1")
	for base in range(2, 37):
		if is_b(a, base) and is_b(b, base) and is_b(c, base):
			na = int(a, base)
			nb = int(b, base)
			nc = int(c, base)
			if (check(na, nb, nc, op)):
				res.append(A[base])
	if (len(res) > 0): print("".join(res))
	else: print("invalid")
