#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int n, m;
vector<vi> graph;
vector<long double> p1, p2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	p2.assign(n, 0);
	p2[0] = 1;
	graph.assign(n, {});
	rep(i, 0, m) {
		ll a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	long double res = 0;
	rep(steps, 1, 10000) {
		p1 = p2;
		p1[n-1] = 0;
		p2.assign(n, 0);
		rep(v, 0, n-1) for (ll u : graph[v])
			p2[u] += p1[v]/sz(graph[v]);
		res += steps*p2[n-1];
	}
	printf("%Lf\n", res);
}
