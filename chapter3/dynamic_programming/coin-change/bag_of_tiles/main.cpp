#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll f(int m, int n) {
    ll res = 1;
    int j = 1;
    rep(i, max(m-n, n)+1, m+1){
        res *= i;
        while (j <= min(m-n, n) && res%j == 0)
            res /= j++;
    }
    while (j <= min(m-n, n))
        res /= j++;
    return res;
}

int main() {
    int G; scanf("%d", &G);
    rep(g, 1, G+1) {
        int m; scanf("%d", &m);
        vi A(m); rep(i, 0, m) scanf("%lld", &A[i]);
        int n, t; scanf("%d%d", &n, &t);
        vector<vector<vi>> dp(m+1, vector<vi>(n+1, vi(t+1, 0)));
        dp[0][0][0] = 1;
        rep(i, 0, m) rep(j, 0, n+1) rep(k, 0, t+1) {
            dp[i+1][j][k] += dp[i][j][k];
            if (j+1 <= n && k + A[i] <= t)
                dp[i+1][j+1][k+A[i]] += dp[i][j][k];
        }
        ll total = f(m, n);
        printf("Game %lld -- %lld : %lld\n", g, dp[m][n][t], total - dp[m][n][t]);
    }
}