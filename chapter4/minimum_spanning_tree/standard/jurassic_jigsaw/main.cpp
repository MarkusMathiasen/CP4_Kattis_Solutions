#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
vector<string> tos;
vector<tuple<int, int, int>> edges;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	tos.assign(n, "");
	rep(i, 0, n) cin >> tos[i];
	rep(i, 0, n) rep(j, i+1, n) {
		int d = 0;
		rep(idx, 0, k) d += tos[i][idx] != tos[j][idx];
		edges.push_back({d, i, j});
	}
	sort(all(edges));
	uf.assign(n, 0);
	rep(i, 1, n) uf[i] = i;
	vector<pii> res;
	int weight = 0;
	for (auto [w,a,b] : edges) {
		if (issame(a, b)) continue;
		same(a, b);
		weight += w;
		res.push_back({a, b});
	}
	printf("%d\n", weight);
	for (auto [a,b] : res)
		printf("%d %d\n", a, b);
}
