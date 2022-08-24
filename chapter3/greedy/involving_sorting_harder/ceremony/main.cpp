#include <bits/stdc++.h>
using namespace std;

int A[100000];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);
	sort(A, A+n);
	int res = 0, start = 0, h = 0;
	while (start < n) {
		while (start < n && A[n-1]-h >= n-start)
			n--, res++;
		if (start == n)
			break;
		h++; res++;
		while (A[start] <= h)
			start++;
	}
	printf("%d\n", res);
}
