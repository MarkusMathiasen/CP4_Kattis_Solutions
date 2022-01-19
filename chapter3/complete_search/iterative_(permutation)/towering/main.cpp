#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> A(6, 0);
	for (int i = 0; i < 6; i++)
		scanf("%d", &A[i]);
	int h1, h2; scanf("%d%d", &h1, &h2);
	sort(A.begin(), A.end());
	do {
		if (A[0] + A[1] + A[2] != h1)
			continue;
		if (max(max(A[0], A[1]), A[2]) != A[0] || min(min(A[0], A[1]), A[2]) != A[2])
			continue;
		if (max(max(A[3], A[4]), A[5]) != A[3] || min(min(A[3], A[4]), A[5]) != A[5])
			continue;
		break;
	} while (next_permutation(A.begin(), A.end()));
	for (int x : A)
		printf("%d ", x);
	printf("\n");
}
