#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n; scanf("%d", &n);
	rep(i, 0, n) {
		map<pii, vector<pii>> graph;
		map<pii, int> dist;
		int s; scanf("%d", &s);
		int x = 0, y = 0;
		while (s--) {
			char c; scanf(" %c", &c);
			int nx = x, ny = y;
			if (c == 'N') nx--;
			if (c == 'S') nx++;
			if (c == 'E') ny++;
			if (c == 'W') ny--;
			graph[{x, y}].push_back({nx, ny});
			graph[{nx, ny}].push_back({x, y});
			x = nx, y = ny;
		}
		queue<pii> q;
		q.push({0, 0});
		dist[{0, 0}] = 0;
		while (!q.empty()) {
			auto [x,y] = q.front(); q.pop();
			for (auto [x2,y2] : graph[{x, y}])
				if (!dist.count({x2, y2}))
					dist[{x2,y2}] = dist[{x,y}]+1,
					q.push({x2,y2});
		}
		printf("%d\n", dist[{x, y}]);
	}

}
