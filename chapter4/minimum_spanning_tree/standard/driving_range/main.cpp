#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<tuple<int, int, int>> edges;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b, w; scanf("%d%d%d", &a, &b, &w);
		edges.push_back({w, a, b});
	}
	sort(all(edges));
	uf.assign(n, 0);
	rep(i, 1, n) uf[i] = i;
	int res = 0;
	int cnt = 0;
	for (auto [w, a, b] : edges) {
		if (issame(a, b)) continue;
		same(a, b);
		res = max(res, w);
		cnt++;
	}
	if (cnt < n-1)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", res);
}
