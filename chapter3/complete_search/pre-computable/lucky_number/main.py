n = int(input())

def search(s):
	if len(s) == n:
		return 1
	res = 0
	for x in "0123456789":
		if int(s+x)%(len(s)+1) == 0:
			res += search(s+x) if len(s) > 0 or x != '0' else 0
	return res
print(search(""))
