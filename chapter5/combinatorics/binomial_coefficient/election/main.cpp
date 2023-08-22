#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
ll n, v1, v2, w;
ll dp[51][51];

ll choose(ll n, ll k) {
	if (k == 0 || n == k) return 1;
	if (dp[n][k]) return dp[n][k];
	return dp[n][k] = choose(n-1, k) + choose(n-1, k-1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> v1 >> v2 >> w;
		if (v2*2 >= n) {
			printf("RECOUNT!\n");
			continue;
		}
		ll m = v1+v2;
		ll need = n/2+1-v1;
		ll win = 0;
		rep(i, need, n-m+1)
			win += choose(n-m, i);
		ll div = 1ll<<(n-m);
		if (win*100/div + ((win*100)%div != 0) > w)
			printf("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n");
		else
			printf("PATIENCE, EVERYONE!\n");
	}
}
