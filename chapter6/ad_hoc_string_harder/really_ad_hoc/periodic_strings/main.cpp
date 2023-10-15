#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	rep(k, 1, sz(s)+1) {
		if (sz(s)%k) continue;
		string sub = s.substr(0, k);
		bool res = true;
		rep(i, 0, sz(s)/k) {
			res &= s.substr(i*k, k) == sub;
			sub = sub.back() + sub;
			sub.pop_back();
		}
		if (res) {
			printf("%lld\n", k);
			return 0;
		}
	}
}
