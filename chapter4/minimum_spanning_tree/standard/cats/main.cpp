#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, M, C;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {
	return find(a) == find(b);
}
void same(int a, int b) {
	uf[find(a)] = find(b);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &M, &C);
		vector<tuple<int, int, int>> edges;
		rep(i, 0, (C*(C-1))/2) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w);
			edges.push_back({w, a, b});
		}
		sort(all(edges));
		uf.assign(C, 0);
		rep(i, 1, C) uf[i] = i;
		int res = 0;
		for (auto [w,a,b] : edges) {
			if (issame(a, b)) continue;
			same(a, b);
			res += w;
		}
		printf(res+C <= M ? "yes\n" : "no\n");
	}
}
