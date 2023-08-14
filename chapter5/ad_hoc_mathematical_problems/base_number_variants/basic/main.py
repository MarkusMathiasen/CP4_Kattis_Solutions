S = "0123456789abcdef"
def is_b(s,b):
	return all([k in S[:b] for k in s])

for _ in range(int(input())):
	i = input()
	A = i.split("#")
	res = len(A[0]) > 0
	res = res and (len(A) == 1 or i[-1] == '#')
	B = [A[0]]
	for i in range(1, len(A), 2):
		res = res and len(A[i]) > 0
		B.append(A[i])
	for i in range(2, len(A), 2):
		res = res and len(A[i]) == 0
	if res:
		base = 10
		for k in B:
			if base > 16 or base < 2:
				res = False
				break
			if not is_b(k, base):
				res = False
				break
			base = int(k, base)
	print(["no","yes"][res])
