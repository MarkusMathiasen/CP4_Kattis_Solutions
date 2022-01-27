#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	int res = 1e9;
	for (int i = 0; i < N; i++)
		res = min(res, A[i] + A[(i+2)%N]);
	printf("%d\n", res);
}
