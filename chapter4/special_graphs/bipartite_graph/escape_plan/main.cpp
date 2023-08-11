#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;

int n, m, t = 1;
vector<vector<vi>> graph;
vector<pdd> robots, holes;
vi vis, match, times = {5, 10, 20};

double dist(int a, int b) {
	return hypot(robots[a].first-holes[b].first, robots[a].second-holes[b].second);
}

int mcbm(int v, int g) {
	if (vis[v]) return 0;
	vis[v] = 1;
	for (int u : graph[g][v]) {
		if (match[u] == -1 || mcbm(match[u], g)) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		graph.assign(3, vector<vi>(n, vi()));
		robots.assign(n, {0, 0});
		rep(i, 0, n) cin >> robots[i].first >> robots[i].second;
		cin >> m;
		holes.assign(m, {0, 0});
		rep(i, 0, m) cin >> holes[i].first >> holes[i].second;
		rep(i, 0, n) rep(j, 0, m) {
			double d = dist(i, j);
			rep(g, 0, 3) if (d <= times[g]*10) graph[g][i].push_back(j);
		}
		printf("Scenario %d\n", t++);
		rep(g, 0, 3) {
			int res = 0;
			match.assign(m, -1);
			rep(i, 0, n) {
				vis.assign(n, 0);
				res += mcbm(i, g);
			}
			printf("In %d seconds %d robot(s) can escape\n", times[g], res);
		}
		printf("\n");
	}
}
