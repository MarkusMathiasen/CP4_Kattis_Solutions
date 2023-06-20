#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MAX_DIST = 1e18;
int n, m;

void fill_dp(vector<vector<ll>>& dp, vector<vector<ll>>& dist, vi& masks) {
	for (int mask : masks) {
		if (mask == 0) continue;
		rep(i, 0, n) {
			if ((mask & (1 << i)) || dp[mask][i] == MAX_DIST) continue;
			int mask2 = mask;
			while (mask2) {
				int j = __builtin_ctz(mask2);
				ll& state = dp[mask - (1<<j)][j];
				state = min(state, dp[mask][i] + dist[i][j]);
				mask2 -= 1 << j;
			}
		}
	}
}

int main() {
	for (int t = 1; true; t++) {
		if (scanf("%d%d", &n, &m) != 2) break;
		vector<vector<ll>> dist(n, vector<ll>(n, MAX_DIST));
		rep(i, 0, m) {
			ll u, v, w;
			scanf("%lld%lld%lld", &u, &v, &w);
			dist[u][v] = dist[v][u] = min(dist[u][v], w);
		}
		// Floyd-Warshall
		rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
		rep(i, 0, n) dist[i][i] = 0;
		vector<vector<ll>> dp_out(1 << n, vector<ll>(n, MAX_DIST));
		vector<vector<ll>> dp_back(1 << n, vector<ll>(n, MAX_DIST));
		dp_out[(1<<n)-2][0] = 0;    // headquaters is 0
		dp_back[(1<<(n-1))-1][n-1] = 0; // attraction is 0
		vi masks; rep(i, 0, 1<<n) masks.push_back(i);
		// Generate masks in decreasing order of size
		// 1 means not visited yet
		sort(all(masks), [](int a, int b){
				return __builtin_popcount(a) > __builtin_popcount(b);
				});
		fill_dp(dp_out, dist, masks);
		fill_dp(dp_back, dist, masks);
		ll ans = MAX_DIST;
		int h = n-2;
		rep(ma, 0, 1 << h) {
			if (__builtin_popcount(ma) != h - h/2) continue;
			int mask2 = ((1<<(n-2))-1) ^ ma;
			int mask = ma << 1;
			mask2 = mask2 << 1;
			int a = mask | (1<<(n-1));  // 1/4
			int b = mask2 | 1;      // 2/4
			int c = mask | 1;       // 3/4
			int d = mask2 | (1<<(n-1)); // 4/4

			ll part1 = MAX_DIST;
			rep(i, 0, n) { // 1/4: dp_out[a][i];
				if ((1 << i) & a) continue;
				rep(j, 0, n) { // 2/4: dp_back[b][j];
					if ((1 << j) & b) continue;
					part1 = min(part1, dp_out[a][i] + dp_back[b][j] + dist[i][j]);
				}
			}
			ll part2 = MAX_DIST;
			rep(i, 0, n) { // 3/4: dp_back[c][i];
				if ((1 << i) & c) continue;
				rep(j, 0, n) { // 4/4: dp_out[d][j];
					if ((1 << j) & d) continue;
					part2 = min(part2, dp_back[c][i] + dp_out[d][j] + dist[i][j]);
				}
			}
			ans = min(ans, part1 + part2);
		}
		printf("Case %d: %lld\n", t, ans);
	}
}
