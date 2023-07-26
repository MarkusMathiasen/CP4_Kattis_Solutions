#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, k;
vector<tuple<int, int, int>> edges;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int mst() {
	uf.assign(n, 0);
	rep(i, 1, n) uf[i] = i;
	int res = 0;
	for (auto [w,a,b] : edges) {
		if (issame(a, b)) continue;
		same(a, b);
		res += w;
	}
	return res;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		char c; int a, b; scanf(" %c%d%d", &c, &a, &b); a--; b--;
		edges.push_back({c == 'B', a, b});
	}
	sort(all(edges));
	int low = mst();
	sort(edges.rbegin(), edges.rend());
	int high = mst();
	printf("%d\n", low <= k && k <= high);
}
