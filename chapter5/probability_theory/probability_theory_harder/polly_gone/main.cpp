#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll F = 1e4;
const ll MAX = 1e18;

ll N, P;
vector<vi> dp;
vi e, p;
string s;

ll read_float(string s) {
	if (s[0] == '1') return F;
	while (sz(s) < 6) s.push_back('0');
	return stoll(s.substr(2, sz(s)-2));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> s;
	P = read_float(s);
	e.assign(N, 0);
	p.assign(N, 0);
	rep(i, 0, N) {
		cin >> e[i] >> s;
		p[i] = read_float(s);
	}
	dp.assign(N+1, vi(F+1, MAX));
	rep(i, 0, N+1) dp[i][0] = 0;
	rep(i, 1, N+1) rep(j, 1, F+1) {
		dp[i][j] = dp[i-1][j];
		if (p[i-1] <= j)
			dp[i][j] = min(dp[i][j], dp[i-1][j-p[i-1]]+e[i-1]);
	}
	ll res = MAX;
	rep(j, P, F+1) res = min(res, dp[N][j]);
	printf("%lld\n", res);
}
