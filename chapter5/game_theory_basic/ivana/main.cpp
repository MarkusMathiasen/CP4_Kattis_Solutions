#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, res = 0;
vi A, presum;
vector<vi> dp;

ll rem(ll a, ll b) {
	if (a < b)
		return presum[n] - presum[b] + presum[a+1];
	return presum[a+1] - presum[b];
}

ll odds(ll a, ll b) {
	if (dp[a][b] != -1) return dp[a][b];
	if (a == b) return dp[a][b] = A[a];
	ll res = 0;
	res = max(res, A[b] + rem(a, (b+1)%n) - odds(a, (b+1)%n));
	res = max(res, A[a] + rem((a-1+n)%n, b) - odds((a-1+n)%n, b));
	return dp[a][b] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, 0);
	rep(i, 0, n) {
		cin >> A[i];
		A[i] %= 2;
	}
	presum.assign(n+1, 0);
	rep(i, 1, n+1) presum[i] = presum[i-1]+A[i-1];
	dp.assign(n, vi(n, -1));
	rep(i, 0, n) {
		ll a = (i-1+n)%n, b = (i+1)%n;
		res += (rem(a, b)-odds(a, b)+A[i])*2 > presum[n];
	}
	printf("%lld\n", res);
}
