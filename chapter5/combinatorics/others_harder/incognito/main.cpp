#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n;
map<string, ll> m;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		m.clear();
		cin >> n;
		while (n--) {
			cin >> s >> s;
			m[s]++;
		}
		ll res = 1;
		for (auto [s,v] : m) res *= v+1;
		printf("%lld\n", res-1);
	}
}
