#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, d, n;
unordered_map<ll, ll> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> d >> n;
		m.clear();
		m[0] = 1;
		ll cnt = 0;
		ll res = 0;
		rep(i, 0, n) {
			ll x; cin >> x;
			cnt = (cnt+x)%d;
			res += m[cnt];
			m[cnt]++;
		}
		printf("%lld\n", res);
	}
}
