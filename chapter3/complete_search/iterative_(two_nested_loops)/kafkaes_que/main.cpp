#include <bits/stdc++.h>
using namespace std;

int main() {
	int K; scanf("%d", &K);
	vector<int> A(K, 0);
	for (int i = 0; i < K; i++)
		scanf("%d", &A[i]);
	int i = 0, res = 0;
	for (; i < K; res++)
		for (int k = 1; k <= 100; k++)
			i += A[i] == k;
	printf("%d\n", res);
}
