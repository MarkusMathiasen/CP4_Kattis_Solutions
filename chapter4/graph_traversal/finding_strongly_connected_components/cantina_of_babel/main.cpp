#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, cnt = 0;
vector<vi> graph, trans;
map<string, int> toi;
vi speakers, vis, comp;
stack<int> st;

int read_lang(string& lang) {
	if (!toi.count(lang)) {
		toi[lang] = sz(toi);
		speakers.push_back(0);
		graph.push_back(vi());
		trans.push_back(vi());
	}
	return toi[lang];
}

void dfs_first(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs_first(u);
	st.push(v);
}

int dfs_second(int v) {
	if (comp[v] != -1) return 0;;
	comp[v] = cnt;
	int res = speakers[v];
	for (int u : trans[v])
		res += dfs_second(u);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	string line; getline(cin, line);
	rep(i, 0, N) {
		getline(cin, line);
		stringstream ss(line);
		string name, lang; ss >> name >> lang;
		int b = read_lang(lang);
		speakers[b]++;
		while (ss >> lang) {
			int a = read_lang(lang);
			graph[a].push_back(b);
			trans[b].push_back(a);
		}
	}
	int L = sz(graph);
	vis.assign(L, 0);
	rep(i, 0, L) dfs_first(i);
	comp.assign(L, -1);
	int res = 0;
	while (!st.empty()) {
		int v = st.top(); st.pop();
		if (comp[v] != -1) continue;
		int siz = dfs_second(v);
		res = max(res, siz);
		cnt++;
	}
	printf("%d\n", N-res);
}
