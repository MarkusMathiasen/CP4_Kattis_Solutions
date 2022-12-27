#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int L = 1e9;

int X, Y, N;
vector<vi> memo, dist;
vector<pii> coords;

int dp(int v, int mask) {
    if (mask == 0) return dist[v][0];
    int& res = memo[v][mask];
    if (res != L) return res;
    int m = mask;
    while (m) {
        int u_pow = m&(-m);
        int u = __builtin_ctz(u_pow)+1;
        res = min(res, dist[v][u] + dp(u, mask-u_pow));
        m -= u_pow;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &N, &N, &X, &Y, &N);
        coords.assign(N+1, {0, 0});
        rep(i, 1, N+1) scanf("%d%d", &coords[i].first, &coords[i].second);
        coords[0] = {X, Y};
        dist.assign(N+1, vi(N+1, 0));
        rep(i, 0, N+1) rep(j, 0, N+1)
            dist[i][j] = abs(coords[i].first-coords[j].first) + abs(coords[i].second-coords[j].second);
        memo.assign(N+1, vi(1<<N, L));
        printf("%d\n", dp(0, (1<<N)-1));
    }
}