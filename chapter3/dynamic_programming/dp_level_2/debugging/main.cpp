#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, r, p;
vector<ll> dp;

ll calc(ll n) {
	if (dp[n] != -1) return dp[n];
	ll res = 1e18;
	rep(i, 2, n+1) {
		ll part = n/i + (n%i > 0);
		res = min(res, calc(part)+r+p*(i-1));
	}
	return dp[n] = res;
}

int main() {
	scanf("%lld%lld%lld", &n, &r, &p);
	dp.assign(n+1, -1);
	dp[1] = 0;
	calc(n);
	printf("%lld\n", dp[n]);
}
