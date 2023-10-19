#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll mod = 1e5;

map<char,char> m = {
	{'(', ')'}, {'[', ']'}, {'{', '}'}
};
const set<char> closing = {')', ']', '}'};
ll N;
string s;
vector<vi> dp;
bool moded = false;

ll matches(char a, char b) {
	if (a == '?' && b == '?') return 3;
	if (a == '?' && closing.count(b)) return 1;
	if (m.count(a) && b == '?') return 1;
	if (m.count(a) && m[a] == b) return 1;
	return 0;
}

ll calc(ll l, ll r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 1;
	if (l+1 == r) return dp[l][r] = 0;
	if (closing.count(s[l])) return dp[l][r] = 0;
	if (m.count(s[r-1])) return dp[l][r] = 0;
	dp[l][r] = 0;
	for (ll i = 0; i <= r-l-2; i += 2) {
		ll mat = matches(s[l], s[l+i+1]);
		ll A = calc(l+1, l+i+1);
		ll B = calc(l+i+2, r);
		dp[l][r] += mat*A*B;
		if (dp[l][r] > mod) {
			moded = true;
			dp[l][r] %= mod;
		}
	}
	return dp[l][r];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> s;
	dp.assign(N+1, vi(N+1, -1));
	ll res = calc(0, N);
	if (moded) printf("%05lld\n", res);
	else printf("%lld\n", res);
}
