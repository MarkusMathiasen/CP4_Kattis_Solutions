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
    int T; scanf("%d", &T);
    while (T--) {
        int t, b, n; scanf("%d%d%d", &t, &b, &n);
        int res = 0;
        while (n) {
            res += (n%b)*(n%b);
            n /= b;
        }
        printf("%d %d\n", t, res);
    }
}
