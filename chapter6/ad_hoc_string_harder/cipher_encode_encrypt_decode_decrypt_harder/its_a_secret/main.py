while True:
	n = int(input())
	if n == 0: break
	grid = [['.']*5 for _ in range(5)]
	key = input().upper().replace('J', 'I')
	seen = [' ']
	cnt = 0
	for c in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
		if c in seen: continue
		grid[cnt//5][cnt%5] = c
		seen.append(c)
		cnt += 1
	for _ in range(n):
		msg = input().upper()
		msg = ("".join(msg.split())+"X").replace('J', 'I')
		i = 0
		while i < len(msg)-1:
			pair = msg[i:i+2]
			i += 2
			if pair[0] == pair[1]:
				pair = msg[i-2] + "X"
				i -= 1
			if pair == "XX":
				print("YY", end="")
				continue
			r1 = 0
			c1 = 0
			r2 = 0
			c2 = 0
			for r in range(5):
				for c in range(5):
					if grid[r][c] == pair[0]:
						r1, c1 = r, c
					if grid[r][c] == pair[1]:
						r2, c2, = r, c
			if r1 == r2:
				print(grid[r1][(c1+1)%5], end="")
				print(grid[r2][(c2+1)%5], end="")
			elif c1 == c2:
				print(grid[(r1+1)%5][c1], end="")
				print(grid[(r2+1)%5][c2], end="")
			else:
				print(grid[r1][c2], end="")
				print(grid[r2][c1], end="")
		print()
	print()
