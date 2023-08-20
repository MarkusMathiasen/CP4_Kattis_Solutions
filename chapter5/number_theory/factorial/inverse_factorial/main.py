from math import log10, floor
d = {}

log_sum = 0
for x in range(1, int(1e9)):
	log_sum += log10(x)
	v = floor(log_sum+1)
	if v in d:
		d[v].append(x)
	else:
		d[v] = [x]
	
	if log_sum > 1e6:
		break

s = input()
L = len(s)
if len(d[L]) == 1:
	print(d[L][0])
else:
	n = int(s)
	res = 1
	f = 1
	for i in range(2, 100):
		if f == n:
			break
		f *= i
		res = i
	print(res)

