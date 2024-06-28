#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, w, h;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> w >> h;
	rep(i, 0, n) {
		ll x; cin >> x;
		printf(x*x <= w*w+h*h ? "DA\n" : "NE\n");
	}
}
