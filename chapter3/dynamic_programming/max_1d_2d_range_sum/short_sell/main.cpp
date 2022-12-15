#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int N, K; scanf("%d%d", &N, &K);
    vector<ll> A(N);
    rep(i,0,N) scanf("%lld", &A[i]);
    vector<ll> B(N-1);
    rep(i,0,N-1) B[i] = 100*(A[i] - A[i+1]) - K;
    ll ans = 0, sum = 0;
    rep(i,0,N-1) {
        sum += B[i];
        sum = max(sum, 0LL);
        ans = max(ans, sum);
    }
    printf("%lld\n", max(0LL, ans-K));
}
