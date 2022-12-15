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
    string s; cin >> s;
    vi a(sz(s));
    rep(i,0,sz(s)) a[i] = s[i] == 'R' ? 1 : -1;
    int res = 0;
    int sum1 = 0, sum2 = 0;
    int start1 = 0, start2 = 0;
    vector<pii> best;
    rep(i,0,sz(a)) {
        sum1 += a[i];
        sum2 -= a[i];
        if (sum1 < 0) {
            sum1 = 0;
            start1 = i + 1;
        }
        if (sum2 < 0) {
            sum2 = 0;
            start2 = i + 1;
        }
        if (sum1 > res) {
            res = sum1;
            best = {{start1, i}};
        } else if (sum1 == res) {
            best.push_back({start1, i});
        }
        if (sum2 > res) {
            res = sum2;
            best = {{start2, i}};
        } else if (sum2 == res) {
            best.push_back({start2, i});
        }
    }
    sort(all(best));
    printf("%d %d\n", best[0].first + 1, best[0].second + 1);
}
