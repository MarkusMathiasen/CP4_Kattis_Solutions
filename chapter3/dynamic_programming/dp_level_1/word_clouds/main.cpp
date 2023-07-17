#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, C;
vi w, h;
vi dp;

int main() {
	scanf("%d%d", &N, &C);
	w.assign(N, 0); h.assign(N, 0);
	rep(i, 0, N) scanf("%d%d", &w[i], &h[i]);
	dp.assign(N+1, 1e9);
	dp[0] = 0;
	rep(i, 0, N) {
		int wid = 0;
		int hig = 0;
		for (int j = i; j < N && wid+w[j] <= C; j++) {
			wid += w[j];
			hig = max(hig, h[j]);
			dp[j+1] = min(dp[j+1], dp[i] + hig);
		}
	}
	printf("%d\n", dp[N]);
}
