#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int low = 100, high = -1;
		while (n--) {
			int x; scanf("%d", &x);
			low = min(low, x);
			high = max(high, x);
		}
		printf("%d\n", (high-low)*2);
	}
}
