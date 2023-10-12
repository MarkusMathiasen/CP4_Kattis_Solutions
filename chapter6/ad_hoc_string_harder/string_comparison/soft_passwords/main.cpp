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
	string S, P; cin >> S >> P;
	bool res = S == P;
	for (char c = '0'; c <= '9'; c++) {
		res |= S == P + c;
		res |= S == c + P;
	}
	for (char& c : P)
		if (isupper(c)) c = (char)tolower(c);
		else if (islower(c)) c = (char)toupper(c);
	res |= P == S;
	printf(res ? "Yes\n" : "No\n");
}
