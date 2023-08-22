a,b,c,d=map(int,input().split())
g=(b-a)/2+a+(d-c)/2+c
a,b,c,d=map(int,input().split())
e=(b-a)/2+a+(d-c)/2+c
if g > e:print("Gunnar")
if g == e:print("Tie")
if g < e:print("Emma")
