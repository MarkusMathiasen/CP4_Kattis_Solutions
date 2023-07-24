#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M, P;
map<string, int> toi;
vector<string> tos;
vector<vi> graph;
vector<ll> blood;


int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
		graph.push_back(vi());
		blood.push_back(-1);
	}
	return toi[s];
}

ll dfs(int v) {
	if (blood[v] != -1) return blood[v];
	ll res = 0;
	for (int u : graph[v])
		res += dfs(u)/2;
	return blood[v] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	string s; cin >> s;
	read_name(s);
	while (N--) {
		string s1, s2, s3; cin >> s1 >> s2 >> s3;
		int c = read_name(s1);
		int p1 = read_name(s2);
		int p2 = read_name(s3);
		graph[c].push_back(p1);
		graph[c].push_back(p2);
	}
	P = sz(graph);
	blood[0] = 1ll<<60;
	int int_res = -1;
	ll am_res = -1;
	while (M--) {
		string s; cin >> s;
		int i = read_name(s);
		ll b = dfs(i);
		if (b > am_res) {
			am_res = b;
			int_res = i;
		}
	}
	printf("%s\n", tos[int_res].c_str());
}
