#include <bits/stdc++.h>
using namespace std;

int A[100000];

int main() {
	int n, x; scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);
	sort(A, A+n);
	int res = 1;
	for (int i = 1; i < n; i++)
		res += A[i] + A[i-1] <= x;
	printf("%d\n", res);
}
