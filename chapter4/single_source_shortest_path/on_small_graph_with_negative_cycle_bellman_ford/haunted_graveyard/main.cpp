#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int,int,int> iii;

const int INF = 1e9;

int W, H, G, E;
vector<vi> grid; // 0 = grass; 1 = gravestone; 2 = haunted_hole
map<pii, vector<iii>> graph;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> W >> H) {
		if (!(W || H)) break;
		graph.clear();
		grid.assign(H, vi(W, 0));
		cin >> G;
		rep(i, 0, G) {
			int x, y; cin >> y >> x;
			grid[x][y] = 1;
		}
		cin >> E;
		rep(i, 0, E) { // add edges for holes
			int x1, y1, x2, y2, t; cin >> y1 >> x1 >> y2 >> x2 >> t;
			grid[x1][y1] = 2;
			graph[{x1,y1}].push_back({x2, y2, t});
		}
		rep(x, 0, H) rep(y, 0, W) { // add edges for grass
			if (grid[x][y]) continue;
			if (x == H-1 && y == W-1) continue;
			rep(i, 0, 4) {
				int nx = x+dx[i], ny = y+dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (grid[nx][ny] == 1) continue;
				graph[{x,y}].push_back({nx, ny, 1});
			}
		}
		vector<vi> dist(H, vi(W, INF));
		dist[0][0] = 0;
		rep(i, 0, W*H)
			rep(x, 0, H) rep(y, 0, W)
				if (dist[x][y] != INF)
					for (auto [nx,ny,t] : graph[{x,y}])
						dist[nx][ny] = min(dist[nx][ny], dist[x][y]+t);
		bool never = false;
		rep(x, 0, H) rep(y, 0, W)
			if (dist[x][y] != INF)
				for (auto [nx,ny,t] : graph[{x,y}])
					never |= dist[nx][ny] > dist[x][y]+t;
		if (never) printf("Never\n");
		else if (dist[H-1][W-1] == INF) printf("Impossible\n");
		else printf("%d\n", dist[H-1][W-1]);
	}
}
