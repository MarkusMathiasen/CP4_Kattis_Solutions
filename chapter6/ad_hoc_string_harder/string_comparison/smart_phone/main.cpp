#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll dist(string goal, string cur) {
	ll pre = 0;
	while (pre < sz(goal) && pre < sz(cur) && cur[pre] == goal[pre])
		pre++;
	return sz(cur)-pre + sz(goal)-pre;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	while (T--) {
		string goal, s, s1, s2, s3; cin >> goal >> s >> s1 >> s2 >> s3;
		ll res = min(dist(goal, s), 1+min(min(dist(goal, s1), dist(goal, s2)), dist(goal, s3)));
		printf("%lld\n", res);
	}
}
