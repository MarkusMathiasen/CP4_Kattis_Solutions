#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, t, n, m, k;
vector<ll> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> t >> n >> m >> k;
		dp.assign(n+1, 0);
		dp[0] = 1;
		rep(i, 1, n+1) {
			rep(j, 1, i+1) {
				if (j >= m && !((j-m)%k)) continue;
				dp[i] += dp[i-j];
			}
		}
		printf("%lld %lld\n", t, dp[n]);

	}
}
