n,d,w = map(int, input().split())
nums = [0]
for row in range(0, n):
	words = input()
	if row%2 == 1: words = words[::-1]
	words = words.strip().split('.')
	nums[-1] += len(words[0])
	for word in words[1:]:
		nums.append(len(word))
res = 0
cur = w
for x in nums:
	if cur+x+1 > w:
		res += 1
		cur = -1
	cur += x+1
print(res)
