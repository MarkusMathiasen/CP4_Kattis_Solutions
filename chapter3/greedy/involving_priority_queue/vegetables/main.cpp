#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> di;

int main() {
	double T; int N; scanf("%lf%d", &T, &N);
	vector<double> A(N, 0);
	double light = 1e9;
	for (int i = 0; i < N; i++)
		scanf("%lf", &A[i]),
		light = min(light, A[i]);
	vector<int> cuts(N, 1);
	priority_queue<di> pq;
	for (int i = 0; i < N; i++)
		pq.emplace(A[i], i);
	int res = 0;
	while (light/pq.top().first < T) {
		res++;
		auto [w,i] = pq.top(); pq.pop();
		cuts[i]++;
		light = min(light, A[i]/cuts[i]);
		pq.emplace(A[i]/cuts[i], i);
	}
	printf("%d\n", res);
}
