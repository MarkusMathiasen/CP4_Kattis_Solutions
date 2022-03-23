#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	long long res = 0;
	while (m--) {
		int x; scanf("%d", &x);
		int can = *lower_bound(A.begin(), A.end(), x);
		res += can-x;
	}
	printf("%lld\n", res);
}
