#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int N; scanf("%d", &N);
	vector<ii> A(N, ii());
	for (int i = 0; i < N; i++)
		scanf("%d%d", &A[i].first, &A[i].second);
	int res = 2e9;
	for (int comb = 1; comb < (1<<N); comb++) {
		int sour = 1, bitter = 0;
		for (int i = 0; i < N; i++)
			if (comb & (1<<i))
				sour *= A[i].first,
				bitter += A[i].second;
		res = min(res, abs(sour-bitter));
	}
	printf("%d\n", res);
}
