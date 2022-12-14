#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int R, S, K;
vector<string> w;

int count(int x, int y) {
    int res = 0;
    rep(i, x+1, x+K-1) rep(j, y+1, y+K-1)
        res += w[i][j] == '*';
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    cin >> R >> S >> K;
    w.assign(R, "");
    rep(i, 0, R) cin >> w[i];
    int x=0,y=0,f=0;
    rep(i, 0, R-K+1) rep(j, 0, S-K+1) {
        int c = count(i, j);
        if (c > f)
            f = c,
            x = i,
            y = j;
    }
    w[x][y] = w[x][y+K-1] = w[x+K-1][y] = w[x+K-1][y+K-1] = '+';
    rep(i, x+1, x+K-1) w[i][y] = w[i][y+K-1] = '|';
    rep(j, y+1, y+K-1) w[x][j] = w[x+K-1][j] = '-';
    printf("%d\n", f);
    rep(i, 0, R) printf("%s\n", w[i].c_str());
}
