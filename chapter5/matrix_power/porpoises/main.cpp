#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MOD = 1e9;

ll T, t, p;

vi mat_mul(vi A, vi B) {
	return {(A[0]*B[0]+A[1]*B[2])%MOD, (A[0]*B[1]+A[1]*B[3])%MOD, (A[2]*B[0]+A[3]*B[2])%MOD, (A[2]*B[1]+A[3]*B[3])%MOD};
}

vi mat_pow(vi A, ll p) {
	if (p == 0) return {1, 0, 0, 1};
	if (p == 1) return A;
	vi res = mat_pow(A, p/2);
	res = mat_mul(res, res);
	if (p%2) res = mat_mul(res, A);
	return res;
}

ll nth(ll p) {
	return mat_pow({1, 1, 1, 0}, p)[1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> t >> p;
		printf("%lld %lld\n", t, nth(p));
	}
}
