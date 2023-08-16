def gcd(a, b):
	if a == 0:
		return b
	return gcd(b%a, a)

def short(n, d):
	g = gcd(n,d)
	return n//g, d//g

def frac_plus(a, b):
	n1,d1 = a
	n2,d2 = b
	n = n1*d2+n2*d1
	d = d1*d2
	return short(n, d)

def frac_minus(a, b):
	n1,d1 = a
	n2,d2 = b
	n = n1*d2-n2*d1
	d = d1*d2
	return short(n, d)

def frac_mult(a, b):
	return short(a[0]*b[0], a[1]*b[1])

def frac_div(a, b):
	return frac_mult(a, (b[1], b[0]))

def to_frac(A):
	if len(A) == 1:
		return A[0], 1
	return frac_plus((A[0], 1), frac_div((1, 1), to_frac(A[1:])))

def to_quo(f):
	n,d = f
	if d == 0:
		return []
	return [n//d] + to_quo((d, n%d))

n1, n2 = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
f1 = to_frac(A)
f2 = to_frac(B)
print(" ".join(map(str, to_quo(frac_plus(f1, f2)))))
print(" ".join(map(str, to_quo(frac_minus(f1, f2)))))
print(" ".join(map(str, to_quo(frac_mult(f1, f2)))))
print(" ".join(map(str, to_quo(frac_div(f1, f2)))))


