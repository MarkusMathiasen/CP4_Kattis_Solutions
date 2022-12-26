#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll IMPOSSIBLE = 1e12+1;

ll S;
ll del_sum = 0;
ll del_target = 0;
vi W = {0}, V = {0};

int main() {
    scanf("%lld", &S);
    ll F_sum = 0;
    rep(i, 0, S) {
        ll D, C, F, U; scanf("%lld%lld%lld%lld", &D, &C, &F, &U);
        del_sum += D;
        if (C + U > F) {
            W.push_back(max(0ll, (C + U + F)/2 + 1 - C));
            V.push_back(D);
        } else F_sum += D;
    }
    S = sz(W);
    del_target = del_sum/2 + 1;
    del_sum -= F_sum;
    vector<vi> dp(S, vi(del_sum+1, IMPOSSIBLE));
    dp[0][0] = 0;
    rep(i, 1, S) rep(j, 0, del_sum+1) {
        dp[i][j] = dp[i-1][j];
        if (j >= V[i] && dp[i-1][j-V[i]] + W[i] < dp[i][j]) {
            dp[i][j] = dp[i-1][j-V[i]] + W[i];
        }
    }
    ll res = IMPOSSIBLE;
    rep(j, del_target, del_sum+1) res = min(res, dp[S-1][j]);
    if (res == IMPOSSIBLE) printf("impossible\n");
    else printf("%lld\n", res);
}