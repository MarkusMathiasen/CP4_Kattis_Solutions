def frac_plus(nom1, denom1, nom2, denom2):
	nom = nom1*denom2 + nom2*denom1
	denom = denom1*denom2
	return nom, denom

def gcd(a, b):
	if a == 0: return b
	if b == 0: return a
	if a > b:
		return gcd(a%b, b)
	if b > a:
		return gcd(a, b%a)
	return a

def to_frac(num, l, i):
	nom1 = num//10**i
	denom1 = 10**(l-i)
	nom2 = num%(10**i)
	denom2 = 10**(l-i)*(10**i-1)
	g = gcd(nom2, denom2)
	nom2 //= g
	denom2 //= g
	nom, denom = frac_plus(nom1, denom1, nom2, denom2)
	g = gcd(nom, denom)
	return nom//g, denom//g
	
while True:
	s = input()
	if s == "0":
		break
	s = s[2:-3]
	num = int(s)
	nom = 1
	denom = 1e18
	for i in range(1, len(s)+1):
		n,d = to_frac(num, len(s), i)
		if d < denom:
			denom = d
			nom = n
	print(str(nom)+"/"+str(denom))
