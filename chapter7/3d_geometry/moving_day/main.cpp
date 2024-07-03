#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, V, largest;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> V;
	rep(i, 0, n) {
		ll l, w, h; cin >> l >> w >> h;
		largest = max(largest, l*w*h);
	}
	printf("%lld\n", largest-V);
}
