#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> s;
		ll cnt = 1;
		rep(i, 2, sz(s))
			cnt += s[i] == s[0];
		ll res = 2*cnt - (s.back() == s.front());
		printf((sz(s)-res)%2 ? "Chikapu\n" : "Bash\n");
	}
}
