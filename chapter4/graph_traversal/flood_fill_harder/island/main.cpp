#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, islands, bridges, busses;
vector<string> grid;
vector<vi> is, graph;
vi bus;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
string line;

void dfs_island(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (is[x][y] || (grid[x][y] != 'X' && grid[x][y] != '#')) return;
	is[x][y] = islands;
	rep(i, 0, 4) dfs_island(x+dx[i], y+dy[i]);
}

void dfs_bus(int i) {
	if (bus[i]) return;
	bus[i] = busses;
	for (int x : graph[i])
		dfs_bus(x);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int t = 1; getline(cin, line) && line != ""; t++) {
		grid.clear();
		grid.push_back(line);
		while (getline(cin, line) && line != "")
			grid.push_back(line);
		n = sz(grid), m = sz(grid[0]);
		islands = bridges = busses = 0;
		is.assign(n, vi(m, 0));
		rep(i, 0, n) rep(j, 0, m) { // count islands
			if (!is[i][j] && (grid[i][j] == '#' || grid[i][j] == 'X')) {
				islands++;
				dfs_island(i, j);
			}
		}
		graph.assign(islands, vi());
		rep(i, 0, n) rep(j, 0, m) { // count bridges and make graph
			if (grid[i][j] == 'X') {
				rep(d, 0, 4) {
					int ni = i + dx[d], nj = j + dy[d];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (grid[ni][nj] == 'B') {
						bridges++;
						while (grid[ni][nj] == 'B') ni += dx[d], nj += dy[d];
						graph[is[i][j]-1].push_back(is[ni][nj]-1);
					}
				}
			}
		}
		bridges /= 2;
		// count busses
		bus.assign(islands, 0);
		rep(i, 0, islands) {
			if (bus[i] == 0) {
				busses++;
				dfs_bus(i);
			}
		}
		printf("Map %d\n", t);
		printf("islands: %d\n", islands);
		printf("bridges: %d\n", bridges);
		printf("buses needed: %d\n\n", busses);
	}
}
