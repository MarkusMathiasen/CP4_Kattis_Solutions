#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_DIST = 1e9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    for (int t = 1; true; t++) {
        // Read input
        int n, m; if (scanf("%d%d", &n, &m) == EOF) break;
        int h = n-2;
        vector<vi> dist(n, vi(n, MAX_DIST));
        rep(i, 0, m) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            dist[u][v] = dist[v][u] = w;
        }
        // Floyd-Warshall
        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        // Generate and sort subsets
        vi subsets; rep(i, 0, 1<<n) subsets.push_back(i);
        sort(all(subsets), [](int a, int b) {
            return __builtin_popcount(a) > __builtin_popcount(b);
        });
        // TSP
        vector<vector<vi>> dp(2, vector<vi>(n, vi(1<<n, MAX_DIST)));
        dp[0][0][(1<<n)-2] = 0;
        dp[1][n-1][(1<<(n-1))-1] = 0;
        rep(s, 0, 2) for (int mask : subsets) rep(v, 0, n) {
            if (dp[s][v][mask] == MAX_DIST) continue;
            int m = mask;
            while (m) {
                int u_pow = m&(-m);
                int u = __builtin_ctz(u_pow);
                dp[s][u][mask-u_pow] = min(dp[s][u][mask-u_pow], dist[v][u] + dp[s][v][mask]);
                m -= u_pow;
            }
        }
        // Find answer
        int res = MAX_DIST;
        rep(sub, 0, 1<<h) {
            if (__builtin_popcount(sub) != h - h/2) continue;
            int nsub = ((~sub)&((1<<h)-1))<<1;
            sub = sub << 1;
            int a = sub + (1 << (n-1)); // Part 1 on the way out
            int b = nsub + 1; // Part 2 on the way out
            int c = sub + 1; // Part 1 on the way back
            int d = nsub + (1 << (n-1)); // Part 2 on the way back
            rep(i, 1, n-1) rep(j, 1, n-1) {
                if (!((1 << i) & sub) && !((1 << j) & sub)) {
                    res = min(res,
                          dp[0][i][a] + dp[1][i][b - (1 << i)] +
                          dp[1][j][c] + dp[0][j][d - (1 << j)]);
                }
            }
        }
        printf("Case %d: %d\n", t, res);
    }
}