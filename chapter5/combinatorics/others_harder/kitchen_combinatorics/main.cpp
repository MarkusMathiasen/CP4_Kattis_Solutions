#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX = 1e18;

ll r, s, m, d, n;
vi b;
vector<vi> dish;
set<pii> incompatible;
bool overflow = false;

ll safe_mul(ll a, ll b) {
	ll i = 62, j = 62;
	while (i && !((1ll<<i)&a)) i--;
	while (j && !((1ll<<j)&b)) j--;
	if (i+j >= 60 || a*b > MAX) {
		overflow = true;
		return 0;
	}
	return a*b;
}
ll safe_add(ll a, ll b) {
	if (a + b > MAX) {
		overflow = true;
		return 0;
	}
	return a+b;
}

int main() {
	// Read input
	cin.tie(0)->sync_with_stdio(0);
	cin >> r >> s >> m >> d >> n;
	b.assign(r+1, 0);
	rep(i, 1, r+1) cin >> b[i];
	dish.assign(s+m+d+1, {});
	rep(i, 1, s+m+d+1) {
		ll k; cin >> k;
		dish[i].assign(k, 0);
		rep(j, 0, k) cin >> dish[i][j];
	}
	rep(i, 0, n) {
		ll a, b; cin >> a >> b;
		incompatible.insert({a, b});
		incompatible.insert({b, a});
	}
	// Solve problem
	ll res = 0;
	rep(i, 1, s+1) rep(j, s+1, s+m+1) rep(k, s+m+1, s+m+d+1) {
		if (incompatible.count({i, j})
			|| incompatible.count({j, k})
			|| incompatible.count({i, k}))
			continue;
		vector<bool> used(r+1, false);
		for (ll x : dish[i]) used[x] = true;
		for (ll x : dish[j]) used[x] = true;
		for (ll x : dish[k]) used[x] = true;
		ll more = 1;
		rep(x, 1, r+1)
			if (used[x]) {
				more = safe_mul(more, b[x]);
				if (overflow)
					goto end;
			}
		res = safe_add(res, more);
		if (overflow)
			goto end;
	}
end:
	if (overflow) printf("too many\n");
	else printf("%lld\n", res);
}
