#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M; scanf("%d%d", &N, &M);
	set<int> pairs;
	while (M--) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		pairs.insert((1<<a)|(1<<b));
	}
	int m = pairs.size();
	int A[m];
	int i = 0;
	for (int x : pairs)
		A[i++] = x;
	int res = 0;
	for (int comb = 0; comb < (1<<N); comb++) {
		int valid = true;
		for (int i = 0; i < m && valid; i++)
			valid &= (comb & A[i]) != A[i];
		res += valid;
	}
	printf("%d\n", res);
}
