#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point {
    int x, y;
    int nxt, prev;
    int area(point a, point b) {
        return abs((a.x - x) * (b.y - y) - (a.y - y) * (b.x - x));
    }
};

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    scanf("%d%d", &n, &m);
    vector<point> p(n+1);
    rep(i,0,n+1) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].nxt = i+1;
        p[i].prev = i-1;
    }
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vector<bool> removed(n+1, false);
    rep(i,1,n) {
        pq.push({p[i].area(p[i-1], p[i+1]), i-1, i, i+1});
    }
    rep(i, 0, n-m) {
        int x, y, z;
        vi v = pq.top(); pq.pop();
        x = v[1], y = v[2], z = v[3];
        if (removed[x] || removed[y] || removed[z]) {
            i--;
            continue;
        }
        removed[y] = true;
        p[x].nxt = z;
        p[z].prev = x;
        if (x > 0) pq.push({p[x].area(p[p[x].prev], p[p[x].nxt]), p[x].prev, x, p[x].nxt});
        if (z < n) pq.push({p[z].area(p[p[z].prev], p[p[z].nxt]), p[z].prev, z, p[z].nxt});
        printf("%d\n", y);
    }
}



