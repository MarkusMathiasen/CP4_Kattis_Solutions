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
    string a, b; cin >> a >> b;
    int x = 0;
    while (x < sz(a) && x < sz(b) && a[x] == b[x]) x++;
    int y = 0;
    while (sz(b)-y > x && a[sz(a)-1-y] == b[sz(b)-1-y]) y++;
    printf("%d\n", max(max(sz(b)-sz(a), 0), sz(b)-x-y));
}
