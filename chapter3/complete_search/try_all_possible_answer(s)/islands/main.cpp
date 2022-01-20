#include <bits/stdc++.h>
using namespace std;

int main() {
	int P; scanf("%d", &P);
	while (P--) {
		int t; scanf("%d", &t);
		int A[12];
		for (int i = 0; i < 12; i++)
			scanf("%d", &A[i]);
		int res = 0;
		for (int i = 1; i <= 10; i++)
			for (int j = i; j <= 10; j++) {
				bool valid = true;
				for (int k = i; k <= j; k++)
					valid &= A[k] > A[i-1] && A[k] > A[j+1];
				res += valid;
			}
		printf("%d %d\n", t, res);
	}
}
