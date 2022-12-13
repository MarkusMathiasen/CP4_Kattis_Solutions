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
    //cin.exceptions(cin.failbit);1]);
    int k;
    while (scanf("%d", &k), k) {
        vector<ll> A(k);
        rep(i,0,k) {
            ll x, y; scanf("%lld.%lld", &x, &y);
            A[i] = x*1000+y;
        }
        sort(all(A));
        vector<ll> presum(k+1, 0);
        rep(i,0,k) presum[i+1] = presum[i] + A[i];
        bool res = false;
        rep(i,1,k) res |= A[i] <= presum[i];
        printf("%s\n", res ? "YES" : "NO");
    }
}
