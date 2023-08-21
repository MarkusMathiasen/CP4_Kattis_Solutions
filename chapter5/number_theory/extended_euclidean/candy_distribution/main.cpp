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
	auto [x2, y2] = ext_gcd(b, a%b);
	return {y2, x2-a/b*y2};
}

ll T, K, C;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> K >> C;
		ll d = gcd(K, C);
		if (d != 1) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		auto [x,y] = ext_gcd(C, K);
		x = ((x%K)+K)%K;
		while (x*C <= K)
			x += K;
		printf("%lld\n", x);
	}
}
