#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 500, MAXT = 200000, MAXR = 2*MAXT+1;

struct cheer {
    int S, D, id;
};

int N, T, R, dist[MAXR], vis[MAXR], cheer_id[MAXR];
cheer cheers[MAXN+1];
priority_queue<pii, vector<pii>, greater<>> pq;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> T; R = 2*T+1;
    rep(i, 1, N+1) {
        cin >> cheers[i].S >> cheers[i].D;
        cheers[i].id = i+1;
    }
    cheers[0] = {1, 1, 1};
    sort(cheers, cheers+N+1, [](const cheer& a, const cheer& b) {
        if (a.S != b.S) return a.S > b.S;
        return a.D < b.D;
    });
    rep(i, 0, R) dist[i] = cheer_id[i] = -1;
    pq.push({0, 0});
    dist[0] = cheer_id[0] = 0;
    while (!vis[T]) {
        auto [d,v] = pq.top(); pq.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        rep(i, cheer_id[v], N + 1) {
            cheer c = cheers[i];
            if (v + c.S >= MAXR || v+c.S < 0) continue;
            if (dist[v]+c.D < dist[v+c.S] || dist[v+c.S] == -1) {
                dist[v+c.S] = dist[v]+c.D;
                cheer_id[v + c.S] = i;
                pq.push({dist[v+c.S], v+c.S});
            }
        }
    }
    vector<int> path;
    int p = T;
    while (p != 0) {
        path.push_back(cheers[cheer_id[p]].id);
        p -= cheers[cheer_id[p]].S;
    }
    printf("%d\n", sz(path));
    rep(i, 0, sz(path)) printf("%d ", path[i]);
    printf("\n");
}
