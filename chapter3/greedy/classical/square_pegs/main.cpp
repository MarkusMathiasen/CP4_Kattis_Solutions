#include <bits/stdc++.h>
using namespace std;

int plots[100], houses[200];

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", plots+i);
	for (int i = 0; i < m; i++)
		scanf("%d", houses+i);
	for (int i = m; i < m+k; i++) {
		int s; scanf("%d", &s);
		houses[i] = floor(sqrt(s*s/2.0));
	}
	sort(plots, plots+n);
	sort(houses, houses+m+k);
	int p = 0, res = 0;
	for (int h = 0; h < m+k; h++) {
		while (p < n && plots[p] <= houses[h])
			p++;
		if (p >= n)
			break;
		res++; p++;
	}
	printf("%d\n", res);
}
