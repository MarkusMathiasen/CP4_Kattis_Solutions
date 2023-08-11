#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
vector<vi> graph;
vi vis, match;

int mcbm(int v, int visa) {
	if (vis[v] == visa) return 0;
	vis[v] = visa;
	for (int u : graph[v]) {
		if (match[u] == -1 || mcbm(match[u], visa)) {
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		graph.assign(n, {0,0});
		rep(i, 0, n) {
			cin >> graph[i][0] >> graph[i][1];
			graph[i][0]--; graph[i][1]--;
		}
		match.assign(2*n, -1);
		vis.assign(n, -1);
		int res = 0;
		rep(i, 0, n)
			res += mcbm(i, i);
		if (res < n) printf("im");
		printf("possible\n");
	}
}
