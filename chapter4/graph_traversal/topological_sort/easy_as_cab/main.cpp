#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char l;
int N, L;
vector<string> words;
vector<vi> graph;
vi deg, topo;
queue<int> q;

void impossible() {printf("IMPOSSIBLE\n");}
void ambiguous() {printf("AMBIGUOUS\n");}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> l >> N;
	L = l-'a'+1;
	words.assign(N, "");
	rep(i, 0, N) cin >> words[i];
	graph.assign(L, vi(L, 0));
	deg.assign(L, 0);
	rep(i, 0, N-1) rep(j, i+1, N) {
		int k = 0;
		while (k < sz(words[i]) && k < sz(words[j])
			&& words[i][k] == words[j][k])
			k++;
		if (k == sz(words[j])) {
			impossible();
			return 0;
		} if (k == sz(words[i]))
			continue;
		int a = words[i][k]-'a', b = words[j][k]-'a';
		if (graph[a][b] == 0) {
			graph[a][b] = 1;
			deg[b]++;
		}
	}
	rep(i, 0, L) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		/*if (q.size() > 1) {
			ambiguous();
			return 0;
		}*/
		int v = q.front(); q.pop();
		topo.push_back(v);
		rep(u, 0, L) if (graph[v][u]) {
			deg[u]--;
			if (deg[u] == 0)
				q.push(u);
		}
	}
	if (sz(topo) < L) {
		impossible();
		return 0;
	}
	bool hamilton = true;
	rep(i, 0, L-1)
		hamilton &= graph[topo[i]][topo[i+1]];
	if (!hamilton) {
		ambiguous();
		return 0;
	}
	for (int v : topo)
		printf("%c", v+'a');
	printf("\n");
}
