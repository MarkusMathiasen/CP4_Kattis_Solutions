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
    int x=0,y=0;
    rep(i, 0, sz(s)) {
        if (s[i] == '1' || s[i] == '3')
            x += 1 << (sz(s)-i-1);
        if (s[i] == '2' || s[i] == '3')
            y += 1 << (sz(s)-i-1);
    }
    printf("%d %d %d\n", sz(s), x, y);
}
