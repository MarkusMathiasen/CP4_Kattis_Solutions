#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, res = 0;
bool impossible = false;
vector<vi> graph;
queue<pii> q; // vertex + color
vi color;

int empty_queue(bool use_1) {
	int a = 0, b = 0;
	while (!q.empty()) {
		auto [v,c] = q.front(); q.pop();
		if (c == color[v]) continue;
		if (c == -color[v]) {
			impossible = true;
			break;
		}
		assert(!color[v]);
		color[v] = c;
		a += c == 1;
		b += c == -1;
		for (int u : graph[v])
			q.push({u, -c});
	}
	if (use_1)
		return a;
	return min(a, b);
}

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vi());
	color.assign(n, 0);
	while (m--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--, b--;
		if (c == 0) {
			q.push({a, -1});
			q.push({b, -1});
		} else if (c == 2) {
			q.push({a, 1});
			q.push({b, 1});
		} else if (c == 1) {
			graph[a].push_back(b);
			graph[b].push_back(a);
		} else assert(false);
	}
	res += empty_queue(true);
	rep(i, 0, n) {
		if (!color[i])
			q.push({i, 1}),
			res += empty_queue(false);
	}
	if (impossible)
		printf("impossible\n");
	else
		printf("%d\n", res);
}
