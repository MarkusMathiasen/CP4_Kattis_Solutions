from functools import lru_cache

@lru_cache(maxsize=None)
def choose(n, k):
	if k == 0 or n == k: return 1
	return choose(n-1, k) + choose(n-1, k-1)

def count(tree, siz, p):
	if p == -1: return 1
	n = siz[tree[p][1]] + siz[tree[p][2]]
	k = siz[tree[p][1]]
	return choose(n, k)*count(tree, siz, tree[p][1])*count(tree, siz, tree[p][2])
	
def get_siz(tree, siz, p):
	if p == -1: return 0
	siz[p] = 1 + get_siz(tree, siz, tree[p][1]) + get_siz(tree, siz, tree[p][2])
	return siz[p]

while True:
	n = int(input())
	if n == 0: break
	A = list(map(int, input().split()))
# Build tree
	tree = [[A[0], -1, -1]] # val; left_idx; right_idx
	for v in A[1:]:
		p = 0
		d = 1 if v < tree[p][0] else 2
		while tree[p][d] != -1:
			p = tree[p][d]
			d = 1 if v < tree[p][0] else 2
		tree[p][d] = len(tree)
		tree.append([v, -1, -1])
# Calc size of subtrees
	siz = [0]*(len(tree)+1)
	get_siz(tree, siz, 0)
# Count subtrees
	res = count(tree, siz, 0)
	print(res)
	

	
