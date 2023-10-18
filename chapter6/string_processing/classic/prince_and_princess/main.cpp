#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, ll> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	ll L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	rep(t, 1, T+1) {
		printf("Case %lld: ", t);
		ll n, p, q; cin >> n >> p >> q;
		vi order(n*n, -1);
		rep(i, 0, p+1) {
			ll x; cin >> x; x--;
			order[x] = i;
		}
		vi l;
		rep(i, 0, q+1) {
			ll x; cin >> x; x--;
			if (order[x] == -1) continue;
			l.push_back(order[x]);
		}
		printf("%lld\n", sz(lis(l)));
	}
}
