#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<long double, int> pli;

int n, m;
vector<vector<pli>> graph;

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		graph.assign(n, vector<pli>());
		while (m--) {
			int a, b; long double w; scanf("%d%d%Lf", &a, &b, &w);
			graph[a].push_back({w,b});
			graph[b].push_back({w,a});
		}
		vector<long double> dist(n, -1);
		priority_queue<pli> pq;
		pq.push({1, 0});
		while (!pq.empty()) {
			auto [d,v] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			for (auto [w,u] : graph[v])
				pq.push({d*w,u});
		}
		printf("%.4Lf\n", dist[n-1]);
	}
}
