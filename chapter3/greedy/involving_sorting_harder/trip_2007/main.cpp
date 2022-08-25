#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		vector<int> A(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		sort(A.begin(), A.end());
		int prev = -1, k = 1, streak = 0;
		for (int i = 0; i < n; i++)
			if (A[i] == prev)
				streak++, k = max(k, streak);
			else
				prev = A[i], streak = 1;
		vector<vector<int>> res(k, vector<int>());
		int j = 0;
		for (int i = 0; i < n; i++)
			res[j].push_back(A[i]), j = (j+1)%k;
		printf("%d\n", k);
		for (int i = 0; i < k; i++) {
			for (int x : res[i])
				printf("%d ", x);
			printf("\n");
		}
		printf("\n");
	}
}
