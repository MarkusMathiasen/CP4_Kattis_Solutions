#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int Re, Rf, n, m;
vector<string> grid;
map<pii, vector<pii>> elsa_graph, father_graph;
int sx, sy, fx, fy;
vi dx = {-1, 1, 0, 0, -1, -1, 1, 1};
vi dy = {0, 0, -1, 1, -1, 1, -1, 1};

int bfs(map<pii, vector<pii>>& graph) {
	queue<pii> q;
	q.push({sx, sy});
	vector<vi> dist(n, vi(m, 1e9));
	dist[sx][sy] = 0;
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		for (auto [nx,ny] : graph[{x,y}]) {
			if (dist[nx][ny] != 1e9) continue;
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx, ny});
		}
	}
	return dist[fx][fy];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> Re >> Rf >> n >> m;
	grid.assign(n, "");
	rep(i, 0, n) cin >> grid[i];
	vector<pii> ws;
	rep(i, 0, n) rep(j, 0, m) {
		if (grid[i][j] == 'S') sx = i, sy = j;
		else if (grid[i][j] == 'G') fx = i, fy = j;
		if (grid[i][j] != 'B') ws.push_back({i,j});
	}
	// make graphs
	rep(i, 0, sz(ws)) rep(j, i+1, sz(ws)) {
		auto [a,b] = ws[i];
		auto [c,d] = ws[j];
		if ((a-c)*(a-c)+(b-d)*(b-d) <= Re*Re)
			elsa_graph[{a,b}].push_back({c,d}),
			elsa_graph[{c,d}].push_back({a,b});
		if ((a-c)*(a-c)+(b-d)*(b-d) <= Rf*Rf
			&& (a == c || b == d))
			father_graph[{a,b}].push_back({c,d}),
			father_graph[{c,d}].push_back({a,b});
	}
	// run bfs
	int elsa = bfs(elsa_graph);
	int father = bfs(father_graph);
	if (elsa == 1e9 && father == 1e9) printf("NO WAY\n");
	else if (father < elsa) printf("NO CHANCE\n");
	else if (elsa < father) printf("GO FOR IT\n");
	else printf("SUCCESS\n");
}
