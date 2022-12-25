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
    int n; scanf("%d", &n);
    int xh, yh, xw, yw; scanf("%d%d%d%d", &xh, &yh, &xw, &yw);
    vector<pii> A;
    rep(i, 0, n) {
        int x, y; scanf("%d%d", &x, &y);
        if (((xh <= x && x <= xw) || (xh >= x && x >= xw)) &&
                ((yh <= y && y <= yw) || (yh >= y && y >= yw)))
            A.emplace_back(x, y);
    }
    sort(all(A), [xh,yh,xw,yw](const pii& a, const pii& b){
        if (a.first != b.first) {
            if ((xh <= xw) == (yh <= yw))
                return a.first < b.first;
            else
                return a.first > b.first;
        }
        return a.second < b.second;
    });
    vi L(sz(A));
    int k = 0;
    rep(i, 0, sz(A)) {
        ll pos = upper_bound(L.begin(), L.begin()+k, A[i].second) - L.begin();
        L[pos] = A[i].second;
        k += pos == k;
    }
    printf("%d\n", k);
}