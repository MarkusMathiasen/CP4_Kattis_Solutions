#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, long double> pid;
typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef tuple<long double,int,int> dii;

int n, m, q;
vector<iii> A;
vector<vector<pid>> graph;
vi pre;
vector<long double> dist;

void print_path(int v) {
	if (v == -2) return;
	assert(v != -1);
	print_path(pre[v]);
	printf("%d ", v);
}

long double euclid(int a, int b) {
	auto [z1,x1,y1] = A[a];
	auto [z2,x2,y2] = A[b];
	return hypot((z2-z1)*5, x2-x1, y2-y1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	rep(i, 0, n) {
		int z, x, y; cin >> z >> x >> y;
		A.push_back({z, x, y});
	}
	graph.assign(n, {});
	rep (i, 0, m) {
		int a, b; string s; cin >> a >> b >> s;
		long double euc = euclid(a, b);
		if (s == "walking" || s == "stairs") {
			graph[a].push_back({b, euc});
			graph[b].push_back({a, euc});
		}
		else if (s == "lift") {
			graph[a].push_back({b, 1});
			graph[b].push_back({a, 1});
		}
		else if (s == "escalator") {
			graph[a].push_back({b, 1});
			graph[b].push_back({a, euc*3});
		}
		else assert(false);
	}
	cin >> q;
	while (q--) {
		dist.assign(n, -1);
		pre.assign(n, -1);
		int start, goal; cin >> start >> goal;
		priority_queue<dii, vector<dii>, greater<dii>> pq;
		pq.push({0, start, -2});
		while (!pq.empty()) {
			auto [d,v,p] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			pre[v] = p;
			dist[v] = d;
			for (auto [u,w] : graph[v])
				pq.push({d+w,u,v});
		}
		print_path(goal);
		//printf("(dist = %Lf)", dist[goal]);
		printf("\n");
	}
}
