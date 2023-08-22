#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 50;

ll T, n, f[N];

int main() {
	f[1] = 1;
	rep(i, 2, N) f[i] = f[i-1] + f[i-2];
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		pii res;
		for (ll b = 1; true; b++) {
			for (ll i = 1; f[i+1]*b <= n; i++) {
				ll x = n-f[i+1]*b;
				if (x%f[i] != 0) continue;
				ll a = x/f[i];
				if (a > b || a < 0) continue;
				res = {a, b};
				goto end;
			}
		}
end:
		printf("%lld %lld\n", res.first, res.second);
	}
}
