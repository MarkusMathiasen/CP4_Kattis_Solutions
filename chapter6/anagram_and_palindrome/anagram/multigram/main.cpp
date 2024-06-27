#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	rep(i, 1, sz(s)) {
		if (sz(s)%i) continue;
		vi f(26, 0);
		rep(j, 0, i) f[s[j]-'a']++;
		bool found = true;
		rep(k, 1, sz(s)/i) {
			vi g(26, 0);
			rep(j, k*i, (k+1)*i) g[s[j]-'a']++;
			rep(j, 0, 26) found &= g[j] == f[j];
			if (!found) break;
		}
		if (found) {
			printf("%s\n", s.substr(0, i).c_str());
			return 0;
		}
	}
	printf("-1\n");
}
