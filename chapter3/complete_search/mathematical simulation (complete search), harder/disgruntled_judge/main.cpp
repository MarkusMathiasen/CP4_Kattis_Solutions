#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);
	for (int a = 0; a <= 10000; a++) {
		for (int b = 0; b <= 10000; b++) {
			int res[n];
			bool valid = true;
			for (int i = 0; i < n && valid; i++) {
				res[i] = (A[i]*a+b)%10001;
				valid &= i == n-1 || (res[i]*a+b)%10001 == A[i+1];
			}
			if (valid) {
				for (int x : res)
					printf("%d\n", x);
				return 0;
			}
		}
	}
}
