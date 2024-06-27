#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> s) {
		set<string> res;
		rep(len, 2, sz(s)+1) rep(i, 0, sz(s)-len+1) {
			bool is_pal = true;
			rep(j, 0, len/2) if (s[i+j] != s[i+len-j-1]) {
				is_pal = false;
				break;
			}
			if (is_pal)
				res.insert(s.substr(i, len));
		}
		for (string s : res) printf("%s\n", s.c_str());
		printf("\n");
	}
}
