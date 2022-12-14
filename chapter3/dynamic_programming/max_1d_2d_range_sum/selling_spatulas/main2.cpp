#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int T = 1440;

int main() {
    ll n;
    while (scanf("%lld", &n), n) {
        vector<ll> a(T, -8);
        rep(i, 0, n) {
            ll x, y, z; scanf("%lld %lld.%lld", &x, &y, &z);
            a[x] += y * 100 + z;
            assert(x < T);
        }
        ll res = 0, sum = 0;
        ll best_start = 0, best_end = 0;
        ll start = 0;
        rep(i, 0, T) {
            sum += a[i];
            if (sum < 0) {
                sum = 0;
                start = i+1;
            } else if (sum > res || (sum == res && i - start < best_end - best_start)) {
                res = sum;
                best_start = start;
                best_end = i;
            }
        }
        if (res > 0)
            printf("%lld.%02lld %lld %lld\n", res / 100, res % 100, best_start, best_end);
        else
            printf("no profit\n");
}
