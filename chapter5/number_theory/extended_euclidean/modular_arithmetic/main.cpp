#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

pii ext_gcd(ll a, ll b) {
	if (b == 0) return {1, 0};
	auto [x2,y2] = ext_gcd(b, a%b);
	return {y2, x2 - a/b*y2};
}

ll mod_inv(ll b, ll m) {
	ll d = gcd(b, m);
	if (d != 1) return -1;
	auto [x,y] = ext_gcd(b, m);
	return ((x%m)+m)%m;
}

ll m, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> m >> t), m || t) {
		while (t--) {
			ll a, b; char c; cin >> a >> c >> b;
			if (c == '+') printf("%lld\n", (a+b)%m);
			else if (c == '-') printf("%lld\n", (a-b+m)%m);
			else if (c == '*') printf("%lld\n", (a*b)%m);
			else if (c == '/') {
				ll mi = mod_inv(b, m);
				if (mi == -1) printf("-1\n");
				else printf("%lld\n", (a*mi)%m);
			}
		}
	}
}
