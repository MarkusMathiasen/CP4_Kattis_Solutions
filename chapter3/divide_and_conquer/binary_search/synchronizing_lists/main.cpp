#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		vector<int> A(n, 0), B(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &B[i]);
		vector<int> A_sorted = A, B_sorted = B;
		sort(A_sorted.begin(), A_sorted.end());
		sort(B_sorted.begin(), B_sorted.end());
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++)
			m[A_sorted[i]] = B_sorted[i];
		for (int x : A)
			printf("%d\n", m[x]);
		printf("\n");
	}
}
