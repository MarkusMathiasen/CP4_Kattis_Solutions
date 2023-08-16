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
    int T; cin >> T;
    while (T--) {
        int n1; cin >> n1;
        vector<int> p1(n1+1, 0);
        rep(i, 0, n1+1) cin >> p1[i];
        int n2; cin >> n2;
        vector<int> p2(n2+1, 0);
        rep(i, 0, n2+1) cin >> p2[i];
        vector<int> res(n1 + n2+1, 0);
        rep(i, 0, n1+1) rep(j, 0, n2+1) res[i + j] += p1[i] * p2[j];
        printf("%d\n", sz(res)-1);
        rep(i, 0, sz(res)) {
            if (i) printf(" ");
            printf("%d", res[i]);
        }
        printf("\n");
    }
}
