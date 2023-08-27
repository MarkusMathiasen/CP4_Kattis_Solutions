#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, B, D;
string person;

bool wins(ll b, ll d, ll h) {
	if (h == 0) {
		if (d == 1) return false;
		return !wins(b, d/2, 1);
	} else {
		if (b == 1) return false;
		return !wins(b/2, d, 0);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> B >> D >> person;
		printf("%s can", person.c_str());
		if (!wins(B, D, person == "Vicky")) printf("not");
		printf(" win\n");
	}
}
