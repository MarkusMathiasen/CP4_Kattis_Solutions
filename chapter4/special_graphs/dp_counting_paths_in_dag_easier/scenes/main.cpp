#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, w, h, MOD = 1e9+7;
vector<vector<ll>> dp;

ll calc(int i, int l) {
	if (i == w) return 1;
	ll& res = dp[i][l];
	if (res != -1) return res;
	res = 0;
	rep(j, 0, min(h, l)+1) res += calc(i+1, l-j);
	return res = res%MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> w >> h;
	dp.assign(w, vector<ll>(n+1, -1));
	ll res = calc(0, n);
	rep(i, 0, h+1) res -= i*w <= n;
	printf("%lld\n", res);
}
