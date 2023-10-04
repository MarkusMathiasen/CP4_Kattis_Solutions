#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bool first_test = true;
	while ((cin >> n), n) {
		if (!first_test) printf("\n");
		first_test = false;
		vi res;
		ll max_w = 0;
		rep(i, 0, n) {
			ll a, b; char op; cin >> a >> op >> b;
			ll r = op == '+' ? a+b : (op == '-' ? a-b : a*b);
			res.push_back(r);
			ll w = 1, p = 10;
			while (to_string(p).size() <= to_string(r).size()) p *= 10, w++;
			max_w = max(max_w, w);
		}
		ll col = 0;
		bool first = true;
		for (ll r : res) {
			if (col+max_w+(!first) > 50) {
				printf("\n");
				col = 0;
				first = true;
			}
			if (!first) {
				col++;
				printf(" ");
			}
			first = false;
			col += max_w;
			printf("%*lld", (int)max_w, r);
		}
		printf("\n");
	}
}
