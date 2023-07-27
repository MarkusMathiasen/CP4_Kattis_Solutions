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
    int N, H, L; cin >> N >> H >> L;
    vector<vi> graph(N);
    vi hi(N, 1e6);
    queue<int> q;
    rep(i,0,H) {
        int x; cin >> x;
        hi[x] = 0;
        q.push(x);
    }
    rep(i,0,L) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : graph[x]) {
            if (hi[y] > hi[x] + 1) {
                hi[y] = hi[x] + 1;
                q.push(y);
            }
        }
    }
    int ans = 0;
    rep(i,1,N) if (hi[i] > hi[ans]) ans = i;
    cout << ans << endl;
}
