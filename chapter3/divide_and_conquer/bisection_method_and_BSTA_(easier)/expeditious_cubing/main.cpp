#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> ts(4, 0);
	for (int i = 0; i < 4; i++) {
		int a, b; scanf("%d.%d", &a, &b);
		ts[i] = a*100 + b;
	}
	sort(ts.begin(), ts.end());
	int a, b; scanf("%d.%d", &a, &b);
	int t = 3 * (a*100 + b);
	if (ts[0] + ts[1] + ts[2] > t) {
		printf("impossible\n");
		return 0;
	}
	if (ts[1] + ts[2] + ts[3] <= t) {
		printf("infinite\n");
		return 0;
	}
	int res = t - ts[1] - ts[2];
	printf("%d.%02d\n", res/100, res%100);
}
