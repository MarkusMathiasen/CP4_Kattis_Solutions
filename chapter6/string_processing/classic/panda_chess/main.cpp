#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N, M, D;
unordered_map<ll, ll> m;
vector<vi> graph;

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (ll x : li) indeg[x]++;
	queue<ll> q; // use priority_queue for lexic. largest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		ll i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (ll x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, ll> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	ll L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}


ll read(ll ic) {
	if (m.count(ic)) return m[ic];
	return m[ic] = sz(m);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> D;
	graph.assign(N, vi());
	rep(i, 0, M) {
		ll a, b; cin >> a >> b;
		a = read(a); b = read(b);
		graph[a].push_back(b);
	}
	vi rank = topoSort(graph);
	vi order(N, 0);
	rep(i, 0, N) order[rank[i]] = i;
	vi typed;
	rep(i, 0, N) {
		ll x; cin >> x;
		if (!m.count(x)) continue;
		typed.push_back(order[m[x]]);
	}
	ll res = sz(lis(typed));
	res = (N-res)*2;
	printf("%lld\n", res);
}
