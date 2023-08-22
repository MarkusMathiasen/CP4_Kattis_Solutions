#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, choose[31][31];



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n+1) rep(j, 0, n+1) {
		if (j > i) continue;
		else if (j == i || j == 0) choose[i][j] = 1;
		else choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
	}
	ll res = 0;
	rep(i, 2, n+1) res += choose[n][i];
	printf("%lld\n", res);
}
