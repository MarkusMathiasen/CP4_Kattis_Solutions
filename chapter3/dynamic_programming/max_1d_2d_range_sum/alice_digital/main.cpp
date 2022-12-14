#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		vi A(n+1);
		rep(i, 1, n+1) scanf("%d", &A[i]);
		vi pre_sum(A);
		rep(i, 1, n+1) pre_sum[i] += pre_sum[i-1];
		int start = 0;
		int res = 0;
		int prev_m = 0;
		rep(i, 1, n+1) {
			if (A[i] < m)
				start = i;
			else if (A[i] == m)
				start = max(start, prev_m),
				prev_m = i;
			if (prev_m > start)
				res = max(res, pre_sum[i] - pre_sum[start]);
		}
		printf("%d\n", res);
	}
}
