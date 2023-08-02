#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;

string p1, p2, line;
int start, goal, n;
vector<string> tos;
unordered_map<string, int> toi;
vector<vector<pii>> graph;

int read_name(string& s) {
	if (!toi.count(s)) {
		toi[s] = sz(toi);
		tos.push_back(s);
		graph.push_back({});
	}
	return toi[s];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> p1 >> p2) {
		tos.clear(); toi.clear(); graph.clear();
		start = read_name(p1);
		goal = read_name(p2);
		cin >> n; getline(cin, line);
		while (n--) {
			getline(cin, line);
			stringstream ss(line);
			vi group; string s;
			while (ss >> s) {
				int x = read_name(s);
				group.push_back(x);
			}
			int g = sz(group);
			rep(i, 0, sz(group)) rep(j, i+1, sz(group)) {
				int a = group[i], b = group[j];
				graph[a].push_back({b, g-2+(b>1)});
				graph[b].push_back({a, g-2+(a>1)});
			}
		}
		vi pre(sz(graph), -1);
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push({0, start, -2});
		vi dist(sz(graph), -1);
		while (!pq.empty()) {
			auto [d,v,p] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			pre[v] = p;
			for (auto [u,w] : graph[v])
				pq.push({d+w, u, v});
		}
		if (dist[goal] == -1) printf("impossible\n");
		else {
			printf("%d", dist[goal]);
			stack<string> st;
			while (goal != -2) {
				st.push(tos[goal]);
				goal = pre[goal];
			}
			while (!st.empty()) {
				printf(" %s", st.top().c_str());
				st.pop();
			}
			printf("\n");
		}
	}

}
