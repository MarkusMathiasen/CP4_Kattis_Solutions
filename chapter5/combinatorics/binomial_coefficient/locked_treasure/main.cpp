#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n, m, dp[31][31];

ll choose(ll n, ll k) {
	if (k == 0 || n == k) return 1;
	if (dp[n][k]) return dp[n][k];
	return dp[n][k] = choose(n-1, k-1) + choose(n-1, k);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		printf("%lld\n", choose(n, m-1));
	}
}
