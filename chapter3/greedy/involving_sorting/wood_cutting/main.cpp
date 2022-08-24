#include <bits/stdc++.h>
using namespace std;

long long c[100000];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			c[i] = 0;
			int w, x; scanf("%d", &w);
			while (w--)
				scanf("%d", &x),
				c[i] += x;
		}
		sort(c, c+N);
		long double total = 0;
		for (int i = 0; i < N; i++)
			total += (N-i)*c[i];
		printf("%.8Lf\n", total/N);
	}
}
