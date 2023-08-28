import sys
for line in sys.stdin:
	if len(line) < 3: break
	a, op, b = line.split()
	a,b = int(a),int(b)
	if op == "+": print((a+b)%10000)
	if op == "*": print((a*b)%10000)
	if op == "^": print(pow(a, b, 10000))
