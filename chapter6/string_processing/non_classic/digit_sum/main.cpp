#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll dsum_pow10(ll N) {
	ll p = 0, k = 1;
	while (k < N) k *= 10, p++;
	return 9ll*p*N/2ll;
}

ll calc(ll N) {
	if (N == 0) return 0;
	ll p = 1;
	while (p*10 <= N) p *= 10;
	ll n = N%p;
	ll res = 0;
	rep(i, 0, N/p) res += i*p + dsum_pow10(p);
	res += N/p * n;
	res += calc(n);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	while (T--) {
		ll A, B; cin >> A >> B;
		printf("%lld\n", calc(B+1) - calc(A));
	}
}
