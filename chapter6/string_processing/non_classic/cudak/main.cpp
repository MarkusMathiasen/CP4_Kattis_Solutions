#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll dsum(ll x) {
	ll res = 0;
	while (x) {
		res += x%10;
		x /= 10;
	}
	return res;
}

void inc_sum(ll& x) {
	ll nines = 0;
	while (x%10 == 9) {
		nines++;
		x /= 10;
	}
	x++;
	while (nines--)
		x = x*10+9;
}

void dec_sum(ll& x) {
	ll p = 10;
	loop:
	while (x%p == 0) p *= 10;
	bool rep = (x%p)/(p/10) == 1;
	x += p-(x%p);
	if (rep)
		goto loop;
}

ll A, B, S;
// pos; sum; is_lower
vector<vector<vi>> dp;
ll calc(ll N) {
	string n = to_string(N);
	dp.assign(sz(n)+1, vector<vi>(S+1, vi(2, 0)));
	dp[0][0][0] = 1;
	rep(pos, 0, sz(n)) rep(sum, 0, S+1) rep(is_lower, 0, 2) {
		ll d = n[pos]-'0';
		rep(nxt, 0, 10)
			if (nxt+sum > S) continue;
			else if (!is_lower && nxt > d) continue;
			else dp[pos+1][sum+nxt][is_lower || nxt < d] += dp[pos][sum][is_lower];
	}
	return dp[sz(n)][S][true];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> B >> S;
	rep(i, dsum(A), S) inc_sum(A);
	ll res1 = calc(B+1) - calc(A);
	ll res2 = A;
	while (dsum(res2) > S)
		dec_sum(res2);
	rep(i, dsum(res2), S)
		inc_sum(res2);
	printf("%lld\n%lld\n", res1, res2);
}
