#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int n, m, d;
vi v1(6, 0), v2(6, 0);
map<pair<vi, vi>, double> dp;

double calc(int d) {
	bool won = true;
	for (int x : v2) won &= x == 0;
	if (won) return 1;
	if (d == 0) return 0;
	if (dp.count({v1, v2})) return dp[{v1, v2}];
	int total = 0;
	for (int x : v1) total += x;
	for (int x : v2) total += x;
	double res = 0;
	rep(i, 0, 6) if (v1[i]) {
		v1[i]--;
		if (i > 0) v1[i-1]++;
		res += calc(d-1)*(v1[i]+1);
		if (i > 0) v1[i-1]--;
		v1[i]++;
	}
	rep(i, 0, 6) if (v2[i]) {
		v2[i]--;
		if (i > 0) v2[i-1]++;
		res += calc(d-1)*(v2[i]+1);
		if (i > 0) v2[i-1]--;
		v2[i]++;
	}
	return dp[{v1, v2}] = res/total;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> d;
	rep(i, 0, n) {
		int x; cin >> x;
		v1[x-1]++;
	}
	rep(i, 0, m) {
		int x; cin >> x;
		v2[x-1]++;
	}
	printf("%lf\n", calc(d));
}
