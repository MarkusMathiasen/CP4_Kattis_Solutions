#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int L = 1e9;

int main() {
    int n; scanf("%d", &n);
    vi A(n); rep(i, 0, n) scanf("%lld", &A[i]);
    vi dp(A[n-1] + A[n-2] + 1, L);
    vi greedy(A[n-1] + A[n-2] + 1, L);
    dp[0] = greedy[0] = 1;
    rep(i, 1, sz(dp)) for (int j = n-1; j >= 0; j--) {
        if (i - A[j] >= 0) {
            dp[i] = min(dp[i], dp[i - A[j]]+1);
            if (greedy[i] == L) greedy[i] = greedy[i - A[j]]+1;
        }
    }
    bool canonical = true;
    rep(i, 0, sz(dp)) if (dp[i] != greedy[i]) canonical = false;
    if (canonical) printf("canonical\n");
    else printf("non-canonical\n");
}