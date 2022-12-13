#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);1]);
    ll k; scanf("%lld", &k);
    vector<ll> A(k);
    rep(i,0,k) scanf("%lld", &A[i]);
    vector<ll> can_produce(k, 0);
    rep(i, 1, k)
        can_produce[i] = (can_produce[i-1] + A[i-1])/2;
    ll owns = 0;
    ll res = 0;
    vector<ll> p(k, 1);
    rep(i, 1, k) p[i] = (p[i-1]*2)%mod;
    for (ll i = k-1; i >= 0; i--) {
        owns *= 2;
        if (owns > A[i]) {
            owns -= A[i];
            A[i] = 0;
        } else {
            A[i] -= owns;
            owns = 0;
        }
        if (A[i] % 2 == 1) {
            if (can_produce[i] > 0) {
                owns++;
            } else {
                res = (res + p[i]) % mod;
            }
        }
    }
    printf("%lld\n", res);
}
