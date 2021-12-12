#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> fruits;

int main() {
	scanf("%d%d", &N, &C);
	fruits.assign(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &fruits[i]);
	int res = 0;
	for (int start = 0; start < N; start++) {
		int att = 0, c = C;
		for (int n = start; n < N; n++)
			if (c >= fruits[n])
				c -= fruits[n],
				att++;
		res = max(res, att);
	}
	printf("%d\n", res);
}
