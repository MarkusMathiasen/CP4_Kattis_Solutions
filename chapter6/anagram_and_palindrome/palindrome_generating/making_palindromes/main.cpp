#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll M = 1e9+7;
ll n;
string s;
vector<vector<vi>> dp;

ll calc(ll l, ll r, ll t) {
	// Base cases
	ll& res = dp[l][r][t];
	if (res != -1) return res;
	if (t > n) return res = 0;
	// Inductive case
	if (l < r) {
		if (s[l-1] != s[r-1])
			return res = (calc(l+1, r, t+1) + calc(l, r-1, t+1) + calc(l, r, t+2)*24ll) % M;
		else
			return res = (calc(l+1, r-1, t) + calc(l, r, t+2)*25ll) % M;
	} else if (l == r) {
		return res = (calc(l+1, r, t+1) + calc(l, r, t+2)*25ll) % M;
	} else { // l == r+1
		if (t == n) return 1;
		else return res = (calc(l, r, t+2)*26ll) % M;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	dp.assign(n+2, vector<vi>(n+2, vi(n+3, -1)));
	printf("%lld\n", calc(1, n, 0));
}
