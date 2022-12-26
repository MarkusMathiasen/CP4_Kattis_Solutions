#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, vi> knapsack(vi& v, vi& w, int W) {
    vector<vi> dp(sz(v) + 1, vi(W + 1, 0));
    vector<vi> keep(sz(v) + 1, vi(W + 1, 0));
    rep(i, 1, sz(v) + 1) rep(j, 0, W+1) {
            dp[i][j] = dp[i-1][j];
            int val = j >= w[i-1] ? dp[i-1][j-w[i-1]] + v[i-1] : 0;
            if (j >= w[i-1] && dp[i][j] < val)
                dp[i][j] = val, keep[i][j] = 1;
        }
    int V = 0;
    int j = 0;
    rep(i, 0, W+1) if (V < dp[sz(v)][i])
            V = dp[sz(v)][i], j = i;
    vi res;
    for (int i = sz(v); i > 0; i--) {
        if (keep[i][j]) {
            j -= w[i-1];
            res.push_back(i-1);
        }
    }
    reverse(all(res));
    return {V, res};
}

int main() {
    int T, N; scanf("%d%d", &T, &N);
    vi V(N); rep(i, 0, N) scanf("%d", &V[i]);
    auto [am, res] = knapsack(V, V, T);
    int top = 0, bot = 0, idx = 0;
    rep(i, 0, N) {
        if (idx < sz(res) && res[idx] == i) {
            printf("%d ", top);
            top += V[i];
            idx++;
        } else {
            printf("%d ", bot);
            bot += V[i];
        }
    }
    printf("\n");
}