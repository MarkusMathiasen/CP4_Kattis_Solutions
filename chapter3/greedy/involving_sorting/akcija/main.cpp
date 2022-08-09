#include <bits/stdc++.h>
using namespace std;

int A[100000];

int main() {
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", A+i),
		res += A[i];
	sort(A, A+n);
	for (int i = n-3; i >= 0; i -= 3)
		res -= A[i];
	printf("%d\n", res);
}
