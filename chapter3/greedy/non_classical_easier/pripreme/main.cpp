#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll maximum(vi& a) {
    ll res = 0;
    rep(i,0,sz(a)) {
        res = max(res, a[i]);
    }
    return res;
}

ll sum(vi& a) {
    ll res = 0;
    rep(i,0,sz(a)) {
        res += a[i];
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n; scanf("%d", &n);
    vi a(n);
    rep(i,0,n) scanf("%lld", &a[i]);
    printf("%lld\n", max(2*maximum(a), sum(a)));
}
