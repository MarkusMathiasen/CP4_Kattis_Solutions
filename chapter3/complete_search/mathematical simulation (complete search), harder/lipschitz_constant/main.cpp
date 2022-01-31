#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> ii;

int main() {
	int N; scanf("%d", &N);
	vector<ii> A(N, ii());
	for (int i = 0; i < N; i++)
		scanf("%d%lf", &A[i].first, &A[i].second);
	sort(A.begin(), A.end());
	double L = 0;
	for (int i = 0; i < N-1; i++)
		L = max(L, abs(A[i].second - A[i+1].second) / abs(A[i].first - A[i+1].first));
	printf("%lf\n", L);
}
