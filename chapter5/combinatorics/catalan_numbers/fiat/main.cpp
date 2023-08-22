#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, mod = 1e9+7;

ll pow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll p = pow(a, b/2, m);
	p = (p*p)%m;
	if (b%2) p = (p*a)%m;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	ll res = 1;
	rep(i, 2, n+1) res = (res*i)%mod;
	res = (res*res)%mod;
	res = (res*(n+1))%mod;
	res = pow(res, mod-2, mod);
	rep(i, 2, 2*n+1) res = (res*i)%mod;
	printf("%lld\n", res);
}
