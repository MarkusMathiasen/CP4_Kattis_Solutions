#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, r, n, t, m, s;
const ll L = 360*60*60;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> r >> n >> t >> m >> s;
		A.assign(L, 0);
		ll pos = 0;
		rep(i, 0, n) {
			if (A[pos]) break;
			A[pos] = true;
			pos = (pos + t*60*60 + m*60 + s) % L;
		}
		ll biggest = 0;
		ll prev = 0;
		rep(i, 0, L) {
			if (A[i]) biggest = max(biggest, i-prev), prev = i;
		}
		biggest = max(biggest, L-prev);
		printf("%lf\n", (double)r*(double)r*M_PI*(double)biggest/(double)L);
	}
}
