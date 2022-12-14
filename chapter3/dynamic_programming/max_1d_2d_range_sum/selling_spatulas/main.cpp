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
    while (cin >> n, n) {
        vector<long double> a(T, -0.08);
        rep(i, 0, n) {
            int t; long double d; cin >> t >> d;
            a[t] += d;
        }
        long double res = 0, sum = 0;
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
            printf("%.2Lf %lld %lld\n", res, best_start, best_end);
        else
            printf("no profit\n");

    }
}
