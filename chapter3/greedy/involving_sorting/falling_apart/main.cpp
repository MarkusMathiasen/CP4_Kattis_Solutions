#include <bits/stdc++.h>
using namespace std;

int A[15];

int main() {
	int n; scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", A+i),
		sum += A[i];
	sort(A, A+n);
	int alice = 0;
	for (int i = n-1; i >= 0; i -= 2)
		alice += A[i];
	printf("%d %d\n", alice, sum-alice);
}
