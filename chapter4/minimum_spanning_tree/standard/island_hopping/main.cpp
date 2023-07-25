#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
vector<pair<long double, long double>> points;

long double dist(int a, int b) {
	return sqrt(
		(points[a].first-points[b].first)*(points[a].first-points[b].first)+
		(points[a].second-points[b].second)*(points[a].second-points[b].second)
	);
}
vi uf;
int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
void same(int a, int b) {
	int x = find(a), y = find(b);
	uf[x] = y;
}
bool issame(int a, int b) {
	return find(a) == find(b);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		points.assign(n, pair<long double, long double>(0, 0));
		rep(i, 0, n) scanf("%Lf%Lf", &points[i].first, &points[i].second);
		vector<tuple<long double, int, int>> edges;
		rep(i, 0, n-1) rep(j, i+1, n)
			edges.push_back({dist(i, j), i, j});
		sort(all(edges));
		uf.assign(n, 0);
		rep(i, 1, n) uf[i] = i;
		long double res = 0;
		for (auto [w,a,b] : edges) {
			if (issame(a, b)) continue;
			same(a, b);
			res += w;
		}
		printf("%Lf\n", res);
	}
}
