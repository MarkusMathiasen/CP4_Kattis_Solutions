d = {}
odds = 0
for c in input():
    d[c] = d.get(c, 0) + 1
    if d[c] % 2 == 1:
        odds += 1
    else:
        odds -= 1
print(max(0, odds - 1))
