#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e9;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int t, n; scanf("%d%d", &t, &n);
        vi A(n); rep(i, 0, n) scanf("%d", &A[i]);
        int max_coin = 0; rep(i, 0, n) max_coin = max(max_coin, A[i]);
        vector<vi> dp(n+1, vi(t+max_coin+1, INF));
        dp[0][0] = 0;
        rep(i, 0, n) rep(j, 0, t+max_coin+1) {
            if (dp[i][j] != INF) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                if (j < t)
                    dp[i+1][j+A[i]] = min(dp[i+1][j+A[i]], dp[i][j]+1);
            }
        }
        rep(j, t, t+max_coin+1) if (dp[n][j] != INF) {
            printf("%d %d\n", j, dp[n][j]);
            break;
        }
    }
}