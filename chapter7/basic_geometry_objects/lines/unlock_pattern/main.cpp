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
    vector<vi> p;
    rep(i, 0, 3) rep(j, 0, 3) {
        int x; scanf("%d", &x);
        p.push_back({x, i, j});
    }
    sort(all(p));
    double res = 0;
    rep(i, 1, 9) res += sqrt((p[i][1]-p[i-1][1])*(p[i][1]-p[i-1][1]) + (p[i][2]-p[i-1][2])*(p[i][2]-p[i-1][2]));
    printf("%lf\n", res);
}