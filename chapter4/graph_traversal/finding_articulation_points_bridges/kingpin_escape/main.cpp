#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, h, cnt=0;
vector<vi> graph;
vi num;

void dfs(int v) {
	if (num[v] != -1) return;
	num[v] = cnt++;
	for (int u : graph[v])
		dfs(u);
}

int main() {
	scanf("%d%d", &n, &h);
	graph.assign(n, vi());
	rep(i, 0, n-1) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	num.assign(n, -1);
	dfs(h);
	vi leafs;
	rep(i, 0, n)
		if (sz(graph[i]) == 1)
			leafs.push_back(i);
	rep(i, 0, n) assert(num[i] != -1);
	sort(all(leafs), [](const int a, const int b) {
		return num[a] < num[b];
	});
	int L = sz(leafs);
	printf("%d\n", L/2 + L%2);
	rep(i, 0, L/2)
		printf("%d %d\n", leafs[i], leafs[i+L/2]);
	if (L%2) {
		printf("%d %d\n", leafs[L-1], leafs[0]);
	}
}
