n,m=map(int,input().split())
p=[ord(c)-ord('a') for c in input()]
lp = len(p)
c=[ord(c)-ord('a') for c in input()]
for i in range(len(c)-1, lp-1, -1):
    diff = (c[i]-p[lp-1])%26
    p = [diff] + p
print("".join([chr(c+ord('a')) for c in p]))
