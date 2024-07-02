#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct rect {
    int x1, y1, x2, y2;
};
struct circ {
    int x, y, r;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int t; cin >> t;
    vector<rect> rec;
    vector<circ> cir;
    while (t--) {
        string s; cin >> s;
        if (s == "rectangle") {
            rect r; cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
            rec.push_back(r);
        } else if (s == "circle") {
            circ c; cin >> c.x >> c.y >> c.r;
            cir.push_back(c);
        } else assert(false);
    }
    int n; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        int res = 0;
        for (rect r : rec)
            res += r.x1 <= x && r.x2 >= x && r.y1 <= y && r.y2 >= y;
        for (circ c : cir)
            res += abs(x-c.x)*abs(x-c.x)+abs(y-c.y)*abs(y-c.y) <= c.r*c.r;
        printf("%d\n", res);
    }
}
