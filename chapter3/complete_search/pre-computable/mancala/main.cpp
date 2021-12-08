#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> conf(2001, vector<int>(81, 0));

int main() {
	for (int i = 1; i <= 2000; i++) {
		conf[i] = conf[i-1];
		for (int j = 1; true; j++) {
			if (conf[i-1][j] == 0) {
				conf[i][j] = j;
				break;
			}
			conf[i][j] = conf[i-1][j]-1;
		}
	}
	int T; scanf("%d", &T);
	while (T--) {
		int t, n; scanf("%d%d", &t, &n);
		vector<int> A = conf[n];
		int l;
		for (l = 80; true; l--)
			if (A[l] != 0)
				break;
		printf("%d %d\n", t, l);
		for (int i = 1; i <= l; i++) {
			if (i%10 == 1)
				printf("%d", A[i]);
			else
				printf(" %d", A[i]);
			if (i%10 == 0)
				printf("\n");
		}
		if (l%10 != 0)
			printf("\n");
	}
}
