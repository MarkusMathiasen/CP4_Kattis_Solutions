#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll indent = 0;

void new_line() {
	printf("\n");
	rep(i, 0, indent)
		printf(" ");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	rep(i, 0, sz(s)) {
		char c = s[i];
		if (c == '{') {
			printf("{");
			indent += 2;
			if (s[i+1] != '}')
				new_line();
		}
		else if (c == ',') {
			printf(",");
			new_line();
		}
		else if (c == '}') {
			indent -= 2;
			new_line();
			printf("}");
		}
		else {
			printf("%c", c);
		}
	}
	printf("\n");
}
