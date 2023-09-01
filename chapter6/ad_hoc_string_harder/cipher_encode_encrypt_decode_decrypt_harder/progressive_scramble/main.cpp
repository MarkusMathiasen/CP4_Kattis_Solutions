#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
char op;
string s;

char toc(ll x) {
	return (char)(x == 0 ? ' ' : 'a'+x-1);
}
ll toi(char x) {
	return x == ' ' ? 0 : x-'a'+1;
}

void encrypt() {
	ll prev = 0;
	for (char c : s) {
		prev = (prev + toi(c))%27;
		printf("%c", toc(prev));
	}
	printf("\n");
}
void decrypt() {
	ll prev = 0;
	for (char c : s) {
		prev = (toi(c)-prev+27)%27;
		printf("%c", toc(prev));
		prev = toi(c);
	}
	printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 0, n) {
		cin >> op;
		getline(cin, s);
		s = s.substr(1, sz(s)-1);
		if (op == 'e')
			encrypt();
		else if (op == 'd')
			decrypt();
	}
}
