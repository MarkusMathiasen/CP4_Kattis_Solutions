#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, p;
vi insec, uf, con;
vector<tuple<int,int,int>> edges;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	insec.assign(n, 0);
	con.assign(n, 0);
	rep(i, 0, p) {
		int x; scanf("%d", &x); x--;
		insec[x] = 1;
	}
	rep(i, 0, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--, b--;
		edges.push_back({c, a, b});
	}
	sort(all(edges));
	uf.assign(n, 0);
	rep(i, 0, n) uf[i] = i;
	int res = 0, cnt = 0;
	for (auto [w,a,b] : edges) {
		if (issame(a,b)) continue;
		if (insec[a] && insec[b] && n > 2) continue;
		if (insec[a] && con[a]) continue;
		if (insec[b] && con[b]) continue;
		same(a, b);
		con[a] = con[b] = 1;
		cnt++;
		res += w;
	}
	if (cnt == n-1) printf("%d\n", res);
	else printf("impossible\n");
}
