from fractions import Fraction
a,b=input().split()
b = int(b)
a1,a2=a.split('.')

stay = a2[:-b]
rep = a2[-b:]

f1 = Fraction(int(a1)*10**len(stay) + (int(stay) if stay != "" else 0), 10**len(stay))
f2 = Fraction(int(rep), 10**len(stay)*(10**len(rep)-1))
res = f1+f2
print(str(res.numerator)+'/'+str(res.denominator))
