#include <bits/stdc++.h>
using namespace std;

int l[1000];

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int P, K, L; scanf("%d%d%d", &P, &K, &L);
		for (int i = 0; i < L; i++)
			scanf("%d", l+i);
		sort(l, l+L, greater<>());
		long long res = 0;
		for (int i = 0; i < L; i++)
			res += (long long)(l[i] * (i/K+1));
		printf("Case #%d: %lld\n", t, res);
	}
}
