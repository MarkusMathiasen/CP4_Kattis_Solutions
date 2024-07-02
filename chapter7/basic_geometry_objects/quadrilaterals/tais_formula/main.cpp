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
    vector<ll> t(n, 0), A(n, 0);
    rep(i, 0, n) {
        ll x, y;
        scanf("%lld %lld.%lld", &t[i], &x, &y);
        A[i] = 2*(10*x+y);
    }
    ll res = 0;
    rep(i, 1, n)
        res += (t[i]-t[i-1])*(A[i]+A[i-1])/2;
    printf("%lf\n", (double)res/20000.0);
}
