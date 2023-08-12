n,p,q=map(int,input().split())
s=p+q
s=s%(2*n)
if s < n:
    print("paul")
else:
    print("opponent")
