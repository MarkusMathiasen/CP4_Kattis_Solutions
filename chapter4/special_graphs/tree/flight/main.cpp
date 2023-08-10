#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vi> graph, mat;
vi dist, p;

int dfs(int v, int d) {
	dist[v] = d;
	int res = v;
	for (int u : graph[v])
		if (mat[v][u] && dist[u] == -1) {
			p[u] = v;
			int k = dfs(u, d+1);
			if (dist[k] > dist[res])
				res = k;
		}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	graph.assign(n, {});
	p.assign(n, -1);
	mat.assign(n, vi(n, 0));
	rep(i, 0, n-1) {
		int a, b; cin >> a >> b; a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		mat[a][b] = mat[b][a] = 1;
	}
	int best_dia = 1e9;
	int ra, rb, ia, ib;
	rep(i, 0, n) rep(j, i+1, n) {
		if (!mat[i][j]) continue;
		mat[i][j] = mat[j][i] = 0;
		dist.assign(n, -1);
		int s = dfs(0, 0);
		dist.assign(n, -1);
		int t = dfs(s, 0);
		int c1 = t;
		while (dist[c1] > dist[t]/2) c1 = p[c1];
		s = 0;
		while (dist[s] != -1) s++;
		s = dfs(s, 0);
		dist.assign(n, -1);
		t = dfs(s, 0);
		int c2 = t;
		while (dist[c2] > dist[t]/2) c2 = p[c2];
		// ---
		mat[c1][c2] = mat[c2][c1] = 1;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);

		dist.assign(n, -1);
		s = dfs(0, 0);
		dist.assign(n, -1);
		t = dfs(s, 0);
		if (dist[t] < best_dia) {
			best_dia = dist[t];
			ra = i, rb = j;
			ia = min(c1, c2), ib = max(c1, c2);
		}

		graph[c1].pop_back();
		graph[c2].pop_back();
		mat[c1][c2] = mat[c2][c1] = 0;
		// ---
		mat[i][j] = mat[j][i] = 1;
	}
	printf("%d\n%d %d\n%d %d\n", best_dia, ra+1, rb+1, ia+1, ib+1);
}
