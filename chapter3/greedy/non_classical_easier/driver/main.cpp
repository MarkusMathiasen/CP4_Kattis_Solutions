#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;



int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n; scanf("%d", &n);
    vi c(n, 0);
    rep(i,0,n-1) scanf("%lld", &c[i]);
    vi t(n);
    rep(i,0,n) scanf("%lld", &t[i]);
    ll min_toll = 1e9;
    int g = -1;
    ll res = 0;
    for (int tim = 0; g < n-1; tim++) {
        if (t[g+1] <= tim) {
            g++;
            min_toll = min(min_toll, c[g]);
            res += c[g];
        } else {
            res += 2*min_toll;
            tim++;
        }
    }
    printf("%lld\n", res);
}
