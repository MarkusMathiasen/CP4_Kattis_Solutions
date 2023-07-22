#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll n, m;
vi state, topo, vis, balls;
vector<vi> graph;

void dfs(ll v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (ll u : graph[v])
		dfs(u);
	topo.push_back(v);
}

int main() {
	scanf("%lld%lld", &n, &m);
	graph.assign(m+1, vi(2, 0));
	graph[0] = {};
	state.assign(m+1, 0);
	vis.assign(m+1, 0);
	rep(i, 1, m+1) {
		char c; scanf(" %c%lld%lld", &c, &graph[i][0], &graph[i][1]);
		state[i] = c == 'R';
	}
	rep(i, 1, m+1)
		dfs(i);
	balls.assign(m+1, 0);
	balls[1] = n;
	for (ll i = m; i > 0; i--) {
		ll v = topo[i];
		balls[graph[v][state[v]]] += balls[v]/2 + balls[v]%2;
		balls[graph[v][1-state[v]]] += balls[v]/2;
		if (balls[v]%2)
			state[v] = 1-state[v];
	}
	rep(i, 1, m+1)
		printf(state[i] ? "R" : "L");
	printf("\n");
}
