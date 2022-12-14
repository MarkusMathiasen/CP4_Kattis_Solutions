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
    int n, p; scanf("%d%d", &n, &p);
    vi a(n);
    rep(i,0,n) scanf("%d", &a[i]), a[i] -= p;
    int res = 0; int sum = 0;
    rep(i, 0, n) {
        sum += a[i];
        sum = max(sum, 0);
        res = max(res, sum);
    }
    printf("%d\n", res);
}
