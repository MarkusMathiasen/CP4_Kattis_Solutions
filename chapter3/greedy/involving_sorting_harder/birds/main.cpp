#include <bits/stdc++.h>
using namespace std;

int A[20002];

int main() {
	int l, d, n; scanf("%d%d%d", &l, &d, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", A+i);
	sort(A+1, A+n+1);
	A[0] = 6-d;
	A[n+1] = l-6+d;
	int res = 0;
	for (int i = 1; i < n+2; i++)
		res += max(0, (A[i]-A[i-1])/d-1);
	printf("%d\n", res);
}
