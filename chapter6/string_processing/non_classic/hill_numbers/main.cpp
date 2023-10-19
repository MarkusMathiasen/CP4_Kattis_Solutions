#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool is_hillnumber(string s) {
	bool rising = true;
	char prev = '0';
	for (char c : s)
		if (rising) {
			if (c < prev) rising = false;
			prev = c;
		} else {
			if (c > prev) return false;
			prev = c;
		}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string n; cin >> n;
	if (!is_hillnumber(n)) {
		printf("-1\n");
		return 0;
	}
	// pos; prev; is_rising; is_lower
	vector<vector<vector<vi>>> dp(sz(n)+1, vector<vector<vi>>(10, vector<vi>(2, vi(2, 0))));
	dp[0][0][1][0] = 1;
	rep(pos, 0, sz(n)) rep(prev, 0, 10) rep(is_rising, 0, 2) rep(is_lower, 0, 2) {
		ll d = n[pos]-'0';
		rep(nxt, 0, 10) {
			if (!is_rising && nxt > prev) continue;
			if (!is_lower && nxt > d) continue;
			dp[pos+1][nxt][is_rising && nxt >= prev][is_lower || nxt < d] += dp[pos][prev][is_rising][is_lower];
		}
	}
	ll res = 0;
	rep(prev, 0, 10) rep(is_rising, 0, 2) rep(is_lower, 0, 2)
		res += dp[sz(n)][prev][is_rising][is_lower];
	printf("%lld\n", res-1);
}
