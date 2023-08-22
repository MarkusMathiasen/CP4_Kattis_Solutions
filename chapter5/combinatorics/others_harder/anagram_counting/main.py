import sys
for line in sys.stdin:
	if line[-1] == '\n':
		line = line[:-1]
	freq = {}
	for c in line:
		if not c in freq:
			freq[c] = 1
		else:
			freq[c] += 1
	res = 1
	for i in range(1, len(line)+1):
		res *= i
	for v in freq.values():
		for i in range(1, v+1):
			res //= i
	print(res)
