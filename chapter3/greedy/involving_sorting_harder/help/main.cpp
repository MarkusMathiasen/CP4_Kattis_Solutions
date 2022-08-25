#include <bits/stdc++.h>
using namespace std;

int N, A[50000];

int main() {
	while (scanf("%d", &N), N) {
		for (int i = 0; i < N; i++)
			scanf("%d", A+i);
		sort(A, A+N);
		printf("%d-A", A[0]);
		for (int i = N-1; i > 0; i--)
			printf(" %d-%c", A[i], (N-i)%2 ? 'B' : 'A');
		printf("\n");
	}
}
