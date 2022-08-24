#include <bits/stdc++.h>
using namespace std;

int t[100000];

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", t+i);
	sort(t, t+N, greater<>());
	int res = N+2;
	for (int i = 0; i < N; i++)
		res = max(res, i + t[i] + 2);
	printf("%d\n", res);
}
