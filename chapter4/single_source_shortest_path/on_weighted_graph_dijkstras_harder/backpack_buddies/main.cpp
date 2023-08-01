#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vector<pii>> graph;

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vector<pii>());
	while (m--) {
		int a, b, w; scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vi dist(n, -1);
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1) continue;
		dist[v] = d;
		for (auto [u,w] : graph[v])
			pq.push({d+w, u});
	}
	int night_time = dist[n-1];
	night_time += 12*((night_time-1)/12);
	dist.assign(n, -1);
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1) continue;
		dist[v] = d;
		int hour = d%12;
		for (auto [u,w] : graph[v]) {
			if (hour+w <= 12)
				pq.push({d+w, u});
			else
				pq.push({d+12-hour+w, u});
		}
	}
	int day_time = dist[n-1];
	day_time += 12*((day_time-1)/12);
	printf("%d\n", day_time-night_time);
}
