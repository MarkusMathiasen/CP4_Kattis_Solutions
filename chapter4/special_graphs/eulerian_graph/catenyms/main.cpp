#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
vector<string> words, res;
vector<vector<pii>> graph;
vi in_deg, out_deg, vis;
vi neigh;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (auto [u,w] : graph[v])
		dfs(u);
}

void euler(int v) {
	while (neigh[v] < sz(graph[v])) {
		auto [u,w] = graph[v][neigh[v]++];
		euler(u);
		res.push_back(words[w]);
	}	
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		// Read input
		cin >> n;
		words.assign(n, "");
		rep(i, 0, n) cin >> words[i];
		graph.assign(26, {});
		in_deg.assign(26, 0);
		out_deg.assign(26, 0);
		rep(i, 0, n) {
			char a = words[i].front(), b = words[i].back();
			graph[a-'a'].push_back({b-'a', i});
			out_deg[a-'a']++;
			in_deg[b-'a']++;
		}
		// Check if possible
		bool possible = true;
		int start = -1, goal = -1;
		rep(i, 0, 26) {
			if (in_deg[i] == out_deg[i]) continue;
			else if (in_deg[i]+1 == out_deg[i] && start == -1) start = i;
			else if (in_deg[i] == out_deg[i]+1 && goal == -1) goal = i;
			else possible = false;
		}
		if (start == -1 && goal != -1) possible = false;
		if (start != -1 && goal == -1) possible = false;
		rep(i, 0, 26) {
			sort(all(graph[i]), [](const pii a, const pii b) {
				return words[a.second] < words[b.second];
			});
		}
		if (start == -1)
			rep(i, 0, 26) if (sz(graph[i])) {
				start = i;
				break;
			}
		// everything should be reachable from start
		vis.assign(26, 0);
		dfs(start);
		rep(i, 0, 26) possible &= vis[i] || !sz(graph[i]);
		if (!possible) {
			printf("***\n");
			continue;
		}
		// Prepare euler tour
		neigh.assign(26, 0);
		res.clear();
		euler(start);
		reverse(all(res));
		assert(sz(res) == n); // THIS FAILS!
		printf("%s", res[0].c_str());
		rep(i, 1, sz(res)) printf(".%s", res[i].c_str());
		printf("\n");
	}
}
