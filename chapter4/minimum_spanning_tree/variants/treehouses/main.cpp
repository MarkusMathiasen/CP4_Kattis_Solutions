#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
typedef vector<int> vi;

int n, e, p;
vector<pdd> A;
vector<tuple<long double, int, int>> edges;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

long double dist(int i, int j) {
	return hypot(A[i].first-A[j].first, A[i].second-A[j].second);
}

int main() {
	scanf("%d%d%d", &n, &e, &p);
	A.assign(n, pii());
	rep(i, 0, n) scanf("%Lf%Lf", &A[i].first, &A[i].second);
	rep(i, 0, n) rep(j, i+1, n) edges.push_back({dist(i, j), i, j});
	sort(all(edges));
	uf.assign(n, 0);
	rep(i, 1, n) uf[i] = i;
	rep(i, 1, e) same(i, 0);
	rep(i, 0, p) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		same(a, b);
	}
	long double res = 0;
	for (auto [w,a,b] : edges) {
		if (issame(a, b)) continue;
		same(a, b);
		res += w;
	}
	printf("%Lf\n", res);
}
