def next(s):
	return int("".join(sorted(str(s+int(str(s)[::-1])))))

def is_creeper(s):
	s = str(s)
	if len(s) < 8: return False
	res = True
	if s[0] == '1':
		res &= s[:4] == "1233"
		res &= s[-4:] == "4444"
		res &= s[4:-4] == '3'*(len(s)-8)
	elif s[0] == '5':
		res &= s[:4] == "5566"
		res &= s[-4:] == "7777"
		res &= s[4:-4] == '6'*(len(s)-8)
	else: res = False
	return res

T = int(input())
for _ in range(T):
	t, m, s = map(int, input().split())
	seen = set()
	found = False
	for i in range(1, m+1):
		if i > 1:
			s = next(s)
		if is_creeper(s):
			print(t, 'C', i)
			found = True
			break
		if s in seen:
			print(t, 'R', i)
			found = True
			break
		seen.add(s)
	if not found:
		print(t, s)
