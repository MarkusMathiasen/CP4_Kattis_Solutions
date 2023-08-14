import sys
A = "0123456789abcdefABCDEF"

for line in sys.stdin:
	if line == "" or line == "\n":
		break
	i = 0
	while i < len(line)-2:
		if line[i:i+2].lower() == '0x':
			cp = i
			s = line[i:i+2]
			a = ""
			for j in range(i+2, i+10):
				if j >= len(line):
					i = j+1
					break
				if not line[j] in A:
					i = j+1
					break
				a = a+line[j]
			if cp == i:
				i += 11
			if len(a):
				print(s+a, int(a, 16))
		else:
			i += 1

