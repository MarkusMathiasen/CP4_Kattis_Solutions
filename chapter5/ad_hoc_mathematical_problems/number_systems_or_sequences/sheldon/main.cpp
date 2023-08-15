#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll X, Y;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> X >> Y;
	ll res = 0;
	rep(N, 1, 64) rep(M, 1, 64) {
		ll x = 0, pos = -1;
		while (pos+N < 63) {
			x = (x<<N)|((1ull<<N)-1);
			pos += N;
			if (pos != N-1 || M == 1)
				res += X <= x && x <= Y;
			if (pos+M < 63) {
				x <<= M;
				pos += M;
				res += X <= x && x <= Y;
			}
			else break;
		}
	}
	printf("%lld\n", res);
}
