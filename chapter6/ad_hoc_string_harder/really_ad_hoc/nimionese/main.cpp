#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string hards = "bcdgknpt";
string softs = "aou";

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	while (cin >> s) {
		stringstream ss(s);
		string part; getline(ss, part, '-');
		ll h = 0;
		rep(i, 0, sz(hards))
			if (abs(tolower(s[0]) - hards[i]) < abs(tolower(s[0]) - hards[h]))
				h = i;
		part[0] = isupper(part[0]) ? (char)toupper(hards[h]) : hards[h];
		printf("%s", part.c_str());
		while (getline(ss, part, '-')) {
			rep(i, 0, sz(hards)) {
				replace(all(part), hards[i], hards[h]);
				replace(all(part), (char)toupper(hards[i]), (char)toupper(hards[h]));
			}
			printf("%s", part.c_str());
		}
		if (hards.find((char)tolower(part.back())) != string::npos) {
			ll so = 0;
			rep(i, 0, sz(softs))
				if (abs(tolower(part.back()) - softs[i]) < abs(tolower(part.back()) - softs[so]))
					so = i;
			printf("%c%c", softs[so], 'h');
		}
		printf(" ");
	}
	printf("\n");
}
