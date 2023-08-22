#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll dp[31], n;

int main() {
	dp[0] = 1;
	rep(i, 2, 31) {
		dp[i] += 3*dp[i-2];
		for (ll j = 4; i-j >= 0; j += 2)
			dp[i] += 2*dp[i-j];
	}
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n != -1)
		printf("%lld\n", dp[n]);
}
