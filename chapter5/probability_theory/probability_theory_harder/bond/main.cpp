#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 20;

long double dp[1<<N];
ll n, p[20][20];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> p[i][j];
	dp[0] = 1;
	for(int i = 0; i < 1<<n; i++) {
		rep(j, 0, n) {
			if (i&(1<<j)) continue;
			dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i]*p[__builtin_popcount(i)][j]/100);
		}
	}
	printf("%Lf\n", dp[(1<<n)-1]*100);
}
