#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int C, n; while (scanf("%d%d", &C, &n) == 2) {
        vi V(n + 1), W(n + 1);
        rep(i, 1, n + 1) scanf("%d%d", &V[i], &W[i]);
        vector <vi> dp(n + 1, vi(C + 1, 0));
        vector <vi> keep(n + 1, vi(C + 1, 0));
        rep(i, 1, n + 1) rep(j, 0, C + 1) {
                dp[i][j] = dp[i - 1][j];
                if (j >= W[i] && dp[i - 1][j - W[i]] + V[i] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - W[i]] + V[i];
                    keep[i][j] = 1;
                }
            }
        vi ans;
        int i = n, best_j = 0;
        rep(j, 0, C + 1) if (dp[i][j] > dp[i][best_j]) best_j = j;
        while (i > 0) {
            if (keep[i][best_j]) {
                ans.push_back(i-1);
                best_j -= W[i];
            }
            i--;
        }
        reverse(all(ans));
        printf("%d\n", sz(ans));
        rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
    }
}