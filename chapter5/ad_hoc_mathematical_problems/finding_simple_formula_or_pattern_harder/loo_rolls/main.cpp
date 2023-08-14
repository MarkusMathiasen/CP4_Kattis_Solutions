#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll rec(ll l, ll n, ll acc) {
    if (l % n == 0)
        return acc;
    return rec(l, n-l%n, acc+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    ll l, n; scanf("%lld%lld", &l, &n);
    printf("%lld\n", rec(l, n, 1));
}
