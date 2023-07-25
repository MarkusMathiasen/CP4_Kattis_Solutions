#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct circle {
	int x, y, r;
};
struct edge {
	long double w;
	int a, b;
};

int N;
vector<circle> circles;
vector<edge> edges;
vi uf;

long double dist(int a, int b) {
	return sqrt(
		(circles[a].x-circles[b].x)*(circles[a].x-circles[b].x)+
		(circles[a].y-circles[b].y)*(circles[a].y-circles[b].y)
	) - circles[a].r - circles[b].r;
}

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	scanf("%d", &N);
	rep(i, 0, N) {
		int x, y, r; scanf("%d%d%d", &x, &y, &r);
		circles.push_back({x, y, r});
	}
	rep(i, 0, N-1) rep(j, i+1, N)
		edges.push_back({dist(i, j), i, j});
	sort(all(edges), [](const edge& a, const edge& b) {
		return a.w < b.w;
	});
	uf.assign(N, 0);
	rep(i, 1, N) uf[i] = i;
	long double res = 0;
	for (edge e : edges) {
		if (issame(e.a, e.b)) continue;
		same(e.a, e.b);
		res += e.w;
	}
	printf("%.8Lf\n", res);
}
