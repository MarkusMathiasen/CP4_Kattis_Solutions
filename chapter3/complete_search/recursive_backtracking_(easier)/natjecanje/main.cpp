#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, S, R; scanf("%d%d%d", &N, &S, &R);
	vector<int> A(N, 1);
	while (S--) {
		int x; scanf("%d", &x);
		A[x-1]--;
	}
	while (R--) {
		int x; scanf("%d", &x);
		A[x-1]++;
	}
	if (A[0] == 2 && A[1] == 0)
		A[1]++;
	if (A[N-1] == 2 && A[N-2] == 0)
		A[N-2]++;
	for (int i = 1; i < N-1; i++)
		if (A[i] == 2)
			if (A[i-1] == 0)
				A[i-1]++;
			else if (A[i+1] == 0)
				A[i+1]++;
	int res = 0;
	for (int x : A)
		res += !x;
	printf("%d\n", res);
}
