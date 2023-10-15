#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n; string s;

void read_word() {
	char c; s = "";
	while (scanf("%c", &c) == 1 && isalpha(c))
		s.push_back((char)tolower(c));
	if (s == "") read_word();

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bool first = true;
	while (scanf("%lld", &n) != EOF) {
		map<string, ll> m;
		while (read_word(), s != "endoftext")
			m[s]++;
		if (!first) printf("\n");
		first = true;
		bool found = false;
		for (auto& [s,cnt] : m) if (cnt == n) {
			printf("%s\n", s.c_str());
			found = true;
		}
		if (!found) printf("There is no such word.\n");
	}
}
