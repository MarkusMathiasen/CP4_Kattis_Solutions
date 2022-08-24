#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int K, N; scanf("%d%d", &K, &N);
		vector<int> A(N, 0);
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		vector<int> B = A;
		sort(B.begin(), B.end());
		int bi = 0;
		for (int i = 0; i < N; i++)
			if (A[i] == B[bi])
				bi++;
		printf("%d %d\n", K, N-bi);
	}
}
