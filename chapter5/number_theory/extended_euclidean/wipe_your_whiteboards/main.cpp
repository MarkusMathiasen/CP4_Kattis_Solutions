#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

ll T, a, b, c;

pii ext_gcd(ll a, ll b) {
	if (b == 0) return {1, 0};
	auto [x2, y2] = ext_gcd(b, a%b);
	return {y2, x2 - a/b*y2};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		auto [x,y] = ext_gcd(a, -b);
		ll d = gcd(a, b);
		x = x*c/d;
		y = -y*c/d;
		ll n = 0;
		while (x+(b/d)*n > 1) n++;
		while (x+(b/d)*n < 1) n--;
		while (y-(a/d)*n < 1) n--;
		printf("%lld %lld\n", x+(b/d)*n, y-(a/d)*n);
	}
}
