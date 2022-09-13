#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int n, b;
	while (scanf("%d%d", &n, &b), n != -1) {
		vector<int> A(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		priority_queue<ii> pq;
		for (int i = 0; i < n; i++)
			pq.emplace(A[i], i);
		vector<int> B(n, 1);
		b -= n;
		while (b--) {
			auto [m,c] = pq.top(); pq.pop();
			B[c]++;
			pq.emplace(A[c]/B[c] + (A[c]%B[c]>0), c);
		}
		printf("%d\n", pq.top().first);
	}
}
