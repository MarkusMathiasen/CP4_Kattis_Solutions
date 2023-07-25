#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n, g, cnt;
vector<vi> graph, comp;

void dfs(int v, int p) {
	int d = -1;
	rep(i, 0, 4) if (graph[v][i] == p) d = i;
	int db = d%2;
	if (comp[v][db] != -1) return;
	comp[v][db] = cnt;
	dfs(graph[v][(d+2)%4], v);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &g); g--;
		graph.assign(n, vi(4, 0));
		rep(i, 0, n) rep(j, 0, 4)
			scanf("%d", &graph[i][j]), graph[i][j]--;
		comp.assign(n, vi(2, -1));
		cnt = 0;
		rep(d, 0, 2) rep(i, 0, n) {
			if (comp[i][d] == -1) {
				dfs(i, graph[i][d]);
				cnt++;
			}
		}
		int res = cnt-1;
		if (comp[g][0] != comp[g][1])
			res--;
		printf("%d\n", res);
	}
}
