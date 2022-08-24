#include <bits/stdc++.h>
using namespace std;

int A[300];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < 3*n; i++)
			scanf("%d", A+i);
		sort(A, A+3*n);
		int res = 0;
		for (int i = n; i < 3*n; i += 2)
			res += A[i];
		printf("%d\n", res);
	}
}
