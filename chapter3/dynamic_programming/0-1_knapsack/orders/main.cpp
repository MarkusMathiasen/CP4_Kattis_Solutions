#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int S = 30000;

vi W;
vector<vi> dp;
vector<vi> bought;

int knap(int i, int s) {
    if (dp[i][s] != -1) return dp[i][s];
    if (W[i] > s) {
        bought[i][s] = 0;
        return dp[i][s] = knap(i-1, s);
    }
    bought[i][s] = knap(i, s-W[i]);
    return dp[i][s] = min(2, knap(i-1, s) + knap(i, s-W[i]));
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n; scanf("%d", &n);
    W.assign(n+1, 0); rep(i, 1, n+1) scanf("%d", &W[i]);
    dp.assign(n+1, vi(S+1, -1));
    bought.assign(n+1, vi(S+1 -1));
    rep(i, 0, S+1) dp[0][i] = i == 0;
    int m; scanf("%d", &m);
    while (m--) {
        int s; scanf("%d", &s);
        int val = knap(n, s);
        if (val == 0) printf("Impossible\n");
        else if (val == 1) {
            int i = n;
            stack<int> res;
            while (i > 0) {
                if (bought[i][s]) {
                    res.push(i);
                    s -= W[i];
                } else i--;
            }
            while (!res.empty())
                printf("%d ", res.top()), res.pop();
            printf("\n");
        }
        else if (val == 2) printf("Ambiguous\n");
        else assert(false);
    }
}