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
    int t; scanf("%d", &t);
    while (t--) {
        int m; scanf("%d", &m);
        vector<pii> dolls(m);
        rep(i, 0, m) {
            scanf("%d%d", &dolls[i].first, &dolls[i].second);
            dolls[i].second = -dolls[i].second;
        }
        sort(all(dolls));
        vi A(m); rep(i, 0, m) A[i] = dolls[i].second;
        vi L(m);
        int k = 0;
        rep(i, 0, m) {
            ll pos = upper_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
            L[pos] = A[i];
            k += pos == k;
        }
        printf("%d\n", k);
    }
}
