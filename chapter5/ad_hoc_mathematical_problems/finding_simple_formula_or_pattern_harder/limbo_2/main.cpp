#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, x, y;

ll msb(ll x) {
	ll res = -1;
	rep(i, 0, 60)
		if ((1ll << i)&x)
			res = i;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> x >> y;
		if (x == y && x == 0) {
			printf("0\n");
			continue;
		}
		ll ix = msb(x), iy = msb(y);
		ll X = 1ll<<(ix+1);
		ll Y = 1ll<<(iy+1);
		X = max(X, Y/2);
		Y = max(X, Y);
		if (X == Y) X /= 2;
		else Y /= 2;
		ll num = X*Y;
		if (Y == X*2)
			num += Y*(x-(1ll<<ix)) + y;
		else if (Y == X)
			num += X*(y-(1ll<<iy)) + x;
		else assert(false);
		printf("%lld\n", num);
	}
}
