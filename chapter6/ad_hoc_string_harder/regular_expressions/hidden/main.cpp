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
	string P, M; cin >> P >> M;
	multiset<char> s;
	for (char c : P) s.insert(c);
	ll i = 0;
	bool res = true;
	for (char c : M) {
		if (c == P[i]) {
			i++;
			s.extract(c);
		}
		else if (s.count(c))
			res = false;
		if (i == sz(P))
			break;
	}
	res &= i == sz(P);
	printf(res ? "PASS\n" : "FAIL\n");
}
