#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int sum = 0;
		vector<int> A(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]),
			sum += A[i];
		double avg = sum/(double)n;
		int above = 0;
		for (int x : A)
			above += x > avg;
		printf("%.3lf%%\n", above*100/(double)n);
	}
}
