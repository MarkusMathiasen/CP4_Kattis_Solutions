#include <bits/stdc++.h>
using namespace std;

struct art {
	int w;
	int h;
	int x;
	int y;
};
int n, chosen;
vector<art> A;

bool intersect(int x, int y) {
	art a = A[x], b = A[y];
	bool ix = a.x < b.x+b.w && a.x+a.w > b.x;
	bool iy = a.y < b.y+b.h && a.y+a.h > b.y;
	return ix && iy;
}

int rec(int idx) {
	if (idx == n)
		return 0;
	int res = rec(idx+1);
	for (int i = 0; i < idx; i++)
		if (chosen&(1<<i) && intersect(i, idx))
			return res;
	chosen ^= (1<<idx);
	res = max(res, rec(idx+1)+A[idx].w*A[idx].h);
	chosen ^= (1<<idx);
	return res;
}

int main() {
	while (scanf("%d", &n), n) {
		A.assign(n, art());
		for (int i = 0; i < n; i++)
			scanf("%d%d%d%d", &A[i].w, &A[i].h, &A[i].x, &A[i].y);
		chosen = 0;
		printf("%d\n", rec(0));
	}
}
