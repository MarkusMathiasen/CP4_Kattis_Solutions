#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int C = 100000, L = 1e9;

vector<vi> make_dp(vi v) {
    vector<vi> dp(sz(v)+1, vi(C+1, L));
    dp[0][0] = 0;
    rep(i, 1, sz(v)+1) rep(j, 0, C+1) {
        dp[i][j] = dp[i-1][j];
        if (j >= v[i-1] && dp[i][j] > dp[i-1][j-v[i-1]] + 1)
            dp[i][j] = dp[i-1][j-v[i-1]] + 1;
    }
    return dp;
}

int main() {
    int H; scanf("%d", &H);
    vi h(H); rep(i, 0, H) scanf("%d", &h[i]);
    vector<vi> dph = make_dp(h);

    int B; scanf("%d", &B);
    vi b(B); rep(i, 0, B) scanf("%d", &b[i]);
    vector<vi> dpb = make_dp(b);

    int best = L;
    rep(c, 1, C+1) best = min(best, dph[H][c] + dpb[B][c]);
    if (best == L) printf("impossible\n");
    else printf("%d\n", best);
}