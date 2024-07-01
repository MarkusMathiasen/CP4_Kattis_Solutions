#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll h, v; cin >> h >> v;
	if (v <= 180) {
		printf("safe\n");
		return 0;
	}
	v -= 180;
	printf("%lld\n", (ll)floor((double)h/sin((double)v/180.*M_PI)));
}
