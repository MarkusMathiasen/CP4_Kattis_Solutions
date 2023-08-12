#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9+7;

ll T, n;

ll ipow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll res = ipow(a, b/2);
	res = (res*res)%MOD;
	if (b%2) res = (res*a)%MOD;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ll res = (8*ipow(9, n-1))%MOD;
		printf("%lld\n", res);
	}
}
