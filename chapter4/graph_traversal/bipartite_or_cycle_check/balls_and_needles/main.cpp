#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int K;
vector<vi> graph1;
vector<vi> graph2;
map<int, int> m1;
map<int, int> m2;
vi vis1, vis2;

bool dfs_cycle(int v, int p, vector<vi>& graph, vi& vis) {
    if (vis[v] == 2) return false;
    if (vis[v] == 1) return true;
    vis[v] = 1;
    for (int u : graph[v])
        if (u == p || u == v) continue;
        else if (dfs_cycle(u, v, graph, vis))
            return true;
    vis[v] = 2;
    return false;
}

int main() {
    scanf("%d", &K);
    graph1.assign(2*K, vi());
    graph2.assign(2*K, vi());
    vis1.assign(2*K, 0);
    vis2.assign(2*K, 0);
    rep(i, 0, K) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        int a = x1*1000000+y1*1000, b = x2*1000000+y2*1000;
        int A = a+z1, B = b+z2;
        if (!m1.count(A))
            m1[A] = sz(m1);
        if (!m1.count(B))
            m1[B] = sz(m1);
        if (!m2.count(a))
            m2[a] = sz(m2);
        if (!m2.count(b))
            m2[b] = sz(m2);
        graph1[m1[A]].push_back(m1[B]);
        graph1[m1[B]].push_back(m1[A]);
        graph2[m2[a]].push_back(m2[b]);
        graph2[m2[b]].push_back(m2[a]);
    }
    bool true_cycle = false;
    rep(i, 0, sz(m1)) true_cycle |= dfs_cycle(i, i, graph1, vis1);
    bool floor_cycle = false;
    rep(i, 0, sz(m2)) floor_cycle |= dfs_cycle(i, i, graph2, vis2);
    if (true_cycle) printf("True closed chains\n");
	else printf("No true closed chains\n");
	if (floor_cycle) printf("Floor closed chains\n");
	else printf("No floor closed chains\n");
}
