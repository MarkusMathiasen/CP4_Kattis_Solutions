#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
string msg, res;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		getline(cin, msg); getline(cin, msg);
		string msg2 = msg;
		msg = "";
		for (char c : msg2)
			if (c != ' ')
				msg.push_back((char)toupper(c));
		res.assign(sz(msg), '.');
		ll cnt = 0;
		rep(start, 0, n) {
			ll i = start;
			while (i < sz(res))
				res[i] = msg[cnt++],
				i += n;
		}
		printf("%s\n", res.c_str());
	}
}
