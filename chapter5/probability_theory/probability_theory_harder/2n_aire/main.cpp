#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
long double t;
vector<long double> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n >> t), n) {
		if (t == 1) {
			dp[0] = 1ll<<n;
			goto end;
		}
		dp.assign(n+1, 0);
		dp[n] = 1ll<<n;
		for (ll i = n-1; i >= 0; i--) {
			long double min_p = (1ll<<i)/dp[i+1];
			min_p = max(min_p, t);
			min_p = min(min_p, 1.0L);
			long double pr_ans = (1-min_p)/(1-t);
			dp[i] = pr_ans*dp[i+1]*(min_p+1)/2 + (1-pr_ans)*(1<<i);
		}
end:
		printf("%.3Lf\n", dp[0]);
	}
}
