#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_T = 1440;

int n, T;
vi p, t, d;
vector<vi> dist;
vector<vi> dp;
int best_points;
int best_mask;

int calc_points(int mask) {
	int res = 0;
	while (mask) {
		int pow_i = mask&(-mask);
		int i = __builtin_ctz(pow_i);
		res += p[i];
		mask -= pow_i;
	}
	return res;
}

bool comp(int mask1, int mask2) {
	while (mask1 && mask2) {
		int pow1 = (-mask1)&mask1;
		int pow2 = (-mask2)&mask2;
		if (pow1 != pow2) return pow1 < pow2;
		mask1 -= pow1; mask2 -= pow2;
	}
	return mask1 == 0;
}

int main() {
	// Read input
	scanf("%d%d", &n, &T);
	p.assign(n+2, 0); t.assign(n+2, 0); d.assign(n, 0);
	rep(i, 0, n) {
		scanf("%d%d%d", &p[i], &t[i], &d[i]);
		if (d[i] == -1) d[i] = T;
	}
	dist.assign(n+2, vi(n+2, 0));
	rep(i, 0, n+2) rep(j, 0, n+2)
		scanf("%d", &dist[i][j]);
	// TSP
	dp.assign(1<<(n+2), vi(n+2, T+1));
	dp[1 << n][n] = 0;
	rep(mask, 1<<n, 1<<(n+1)) rep(i, 0, n+1) {
		if (dp[mask][i] > T || !(mask & (1 << i))) continue;
		rep(j, 0, n) {
			int new_mask = mask | (1 << j);
			if (new_mask == mask) continue;
			int new_t = dp[mask][i] + dist[i][j] + t[j];
			if (new_t > d[j]) continue;
			dp[new_mask][j] = min(dp[new_mask][j], new_t);
		}
	}
	// Find solution
	best_points = -1;
	best_mask = 0;
	rep(mask, 1<<n, 1<<(n+1)) rep(i, 0, n+1) {
		if (!(mask & (1 << i))) continue;
		if (dp[mask][i] + dist[i][n+1] > T) continue;
		int stripped_mask = mask & ((1<<n)-1);
		int points = calc_points(stripped_mask);
		if (points > best_points)
			best_points = points,
			best_mask = stripped_mask;
		else if (points == best_points && comp(stripped_mask, best_mask))
			best_mask = stripped_mask;
	}
	// Print solution
	if (best_points == -1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", best_points);
	while (best_mask) {
		int i = __builtin_ctz(best_mask);
		best_mask -= 1<<i;
		printf("%d ", i+1);
	}
	printf("\n");
}
