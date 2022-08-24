#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p; scanf("%d%d", &n, &p);
	vector<int> P;
	int y;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (i == p)
			y = x;
		else
			P.push_back(x);
	}
	sort(P.begin(), P.end());
	P.insert(P.begin(), y);
	int t = 300, ac = 0, pen = 0;
	for (int i = 0; i < n; i++) {
		t -= P[i];
		if (t < 0)
			break;
		pen += 300 - t;
		ac++;
	}
	printf("%d %d\n", ac, pen);
}
