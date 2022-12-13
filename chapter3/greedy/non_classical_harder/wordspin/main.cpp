#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);1]);
    string a, b; cin >> a >> b;
    vector<vi> diff;
    int prev = 0;
    rep(i, 0, sz(a)) {
        int d = a[i] - b[i];
        if (sign(d) != sign(prev) || !diff.size())
            diff.push_back({abs(d)});
        else
            diff.back().push_back(abs(d));
        prev = d;
    }
    int res = 0;
    for (vi& v : diff) {
        bool increasing = true;
        int prev = 0, from = 0;
        for (int x : v) {
            if (increasing && prev > x) {
                increasing = false;
                res += prev-from;
            } else if (!increasing && prev < x) {
                increasing = true;
                from = prev;
            }
            prev = x;
        }
        if (increasing) res += prev-from;
    }
    printf("%d\n", res);
}
