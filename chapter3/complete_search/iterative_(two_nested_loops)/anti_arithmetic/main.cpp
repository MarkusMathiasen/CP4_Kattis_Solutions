#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		scanf(": ");
		vector<int> A(n, 0);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			A[x] = i;
		}
		bool res = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (A[j] <= A[i])
					continue;
				int diff = j-i;
				res &= j+diff < 0 || j+diff >= n || A[j+diff] <= A[j];
			}
		printf(res ? "yes\n" : "no\n");
	}
}
