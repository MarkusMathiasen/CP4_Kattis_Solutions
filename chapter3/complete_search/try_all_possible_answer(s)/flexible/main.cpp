#include <bits/stdc++.h>
using namespace std;

int main() {
	int W, P; scanf("%d%d", &W, &P);
	int A[P+2];
	A[0] = 0;
	A[P+1] = W;
	for (int i = 1; i <= P; i++)
		scanf("%d", &A[i]);
	set<int> res;
	for (int i = 0; i < P+1; i++)
		for (int j = i+1; j < P+2; j++)
			res.insert(A[j]-A[i]);
	for (int x : res)
		printf("%d ", x);
	printf("\n");
}
