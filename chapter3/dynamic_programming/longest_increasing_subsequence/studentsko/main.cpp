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
    vi A(N); rep(i, 0, N) scanf("%d", &A[i]);
    vector<pii> B; rep(i, 0, N) B.emplace_back(A[i], i);
    sort(all(B));
    rep(i, 0, N/K)
        rep(j, i*K, (i+1)*K)
            A[B[j].second] = B[i].first;
    vi L(N);
    int k = 0;
    rep(i, 0, N) {
        ll pos = upper_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        k += pos == k;
    }
    printf("%d\n", N-k);
}
