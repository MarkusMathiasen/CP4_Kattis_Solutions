#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, N, cnt;
vector<vi> graph, trans;
map<char, int> toi;
vector<char> toc;
vi comp;
stack<int> st;

int read_char(char c) {
	if (!toi.count(c)) {
		graph.push_back(vi());
		trans.push_back(vi());
		toi[c] = sz(toi);
		toc.push_back(c);
	}
	return toi[c];
}

void dfs_first(int v) {
	if (comp[v]) return;
	comp[v] = 1;
	for (int u : graph[v])
		dfs_first(u);
	st.push(v);
}

void dfs_second(int v) {
	if (comp[v] != -1) return;
	comp[v] = cnt;
	for (int u : trans[v])
		dfs_second(u);
}

int main() {
	while (scanf("%d", &n), n) {
		toi.clear();
		toc.clear();
		graph.clear();
		trans.clear();
		while (n--) {
			vector<char> A(6, ' ');
			rep(i, 0, 6) scanf(" %c", &A[i]);
			vi B(6, 0);
			rep(i, 0, 6) B[i] = read_char(A[i]);
			rep(i, 0, 5)
				if (B[i] != B[5])
					graph[B[5]].push_back(B[i]),
					trans[B[i]].push_back(B[5]);
		}
		int N = sz(graph);
		comp.assign(N, 0);
		rep(i, 0, N) dfs_first(i);
		cnt = 0;
		comp.assign(N, -1);
		while (!st.empty()) {
			int v = st.top(); st.pop();
			if (comp[v] == -1) {
				dfs_second(v);
				cnt++;
			}
		}
		vector<vector<char>> comps(cnt, vector<char>());
		rep(i, 0, N) comps[comp[i]].push_back(toc[i]);
		rep(i, 0, cnt) sort(all(comps[i]));
		sort(all(comps));
		for (vector<char>& A : comps) {
			for (char c : A)
				printf("%c ", c);
			printf("\n");
		}
		printf("\n");
	}
}
