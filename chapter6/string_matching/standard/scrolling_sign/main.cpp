#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int k, w; cin >> k >> w;
		vector<string> A(w, "");
		for (int i = 0; i < w; i++)
			cin >> A[i];
		int res = k;
		for (int i = 1; i < w; i++)
			for (int j = 0; j <= k; j++)
				if (A[i-1].substr(j) == A[i].substr(0, k-j)) {
					res += j;
					break;
				}
		printf("%d\n", res);
	}
}
