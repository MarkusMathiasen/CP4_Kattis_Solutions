#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int lis(const vector<int>& A) {
    vi L(sz(A));
    int k = 0;
    rep(i, 0, sz(A)) {
        ll pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        k += pos == k;
    }
    return k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n; scanf("%d", &n);
    vi A(n); rep(i, 0, n) scanf("%d", &A[i]);
    int res = 0;
    rep(i, 0, n) {
        vi B, C;
        rep(j, i, n) {
            if (A[j] >= A[i])
                B.push_back(A[j]);
            if (A[j] <= A[i])
                C.push_back(-A[j]);
        }
        res = max(res, lis(B)+lis(C)-1);
    }
    printf("%d\n", res);
}
