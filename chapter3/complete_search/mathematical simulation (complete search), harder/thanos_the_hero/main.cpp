#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	long long res = 0;
	for (int i = N-2; i >= 0; i--) {
		int v = min(A[i], A[i+1]-1);
		res += A[i]-v;
		A[i] = v;
	}
	printf("%lld\n", A[0] < 0 ? 1ll : res);
}
