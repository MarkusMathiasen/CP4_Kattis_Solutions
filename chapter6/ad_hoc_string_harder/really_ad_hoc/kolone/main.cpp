#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, t;
string a, b, s, s2;
set<char> A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> a >> b >> t;
	for (char c : a) A.insert(c);
	for (char c : b) B.insert(c);
	reverse(all(a));
	s = a + b;
	while (t--) {
		s2 = s;
		rep(i, 0, sz(s)-1) {
			if (A.count(s[i]) && B.count(s[i+1]))
				swap(s2[i], s2[i+1]);
		}
		s = s2;
	}
	printf("%s\n", s.c_str());
}

