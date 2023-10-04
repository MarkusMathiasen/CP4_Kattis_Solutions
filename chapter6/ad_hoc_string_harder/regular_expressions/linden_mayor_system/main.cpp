#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

map<char, string> m;
ll n, rounds;
string s1, s2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> rounds;
	rep(i, 0, n) {
		cin >> s1 >> s2 >> s2;
		m[s1[0]] = s2;
	}
	cin >> s1;
	rep(i, 0, rounds) {
		s2.clear();
		for (char c : s1)
			if (m.count(c))
				s2 += m[c];
			else
				s2.push_back(c);
		swap(s1, s2);
	}
	printf("%s\n", s1.c_str());
}
