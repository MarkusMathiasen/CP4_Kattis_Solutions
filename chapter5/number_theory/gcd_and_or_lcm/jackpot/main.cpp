#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ll res = 1;
		rep(i, 0, n) {
			int x; cin >> x;
			if (res <= (ll)1e9)
				res = lcm(res, x);
			else
				res = 1e9+1;
		}
		if (res <= (ll)1e9)
			printf("%lld\n", res);
		else
			printf("More than a billion.\n");
	}
}
