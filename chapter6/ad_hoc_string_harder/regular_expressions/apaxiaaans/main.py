s=input()
res=s[0]
for c in s:
    if c != res[-1]:
        res += c
print(res)
