#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M;
vector<string> tos;
unordered_map<string, int> toi;
vector<vi> graph;
vi color;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	graph.assign(N, vi());
	color.assign(N, 0);
	tos.assign(N, "");
	rep(i, 0, N) {
		cin >> tos[i];
		toi[tos[i]] = i;
	}
	cin >> M;
	while (M--) {
		string s1, s2; cin >> s1 >> s2;
		int a = toi[s1], b = toi[s2];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int> q;
	rep(i, 0, N) {
		if (!color[i]) {
			color[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int v = q.front(); q.pop();
				for (int u : graph[v]) {
					if (!color[u]) {
						color[u] = -color[v];
						q.push(u);
					} else if (color[u] == color[v]) {
						printf("impossible\n");
						return 0;
					}
				}
			}
		}
	}
	rep(i, 0, N) if (color[i] == 1) printf("%s ", tos[i].c_str());
	printf("\n");
	rep(i, 0, N) if (color[i] == -1) printf("%s ", tos[i].c_str());
	printf("\n");
}
