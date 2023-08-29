#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll O, N;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> O >> s >> N;
	ll bad = 0;
	rep(i, 0, N) {
		ll vowels = 0;
		for (char& c : s) {
			c -= 'a';
			c = (char)(c+O)%26;
			c += 'a';
			vowels += c == 'a';
			vowels += c == 'e';
			vowels += c == 'i';
			vowels += c == 'o';
			vowels += c == 'u';
			vowels += c == 'y';
		}
		bad += vowels*3 >= sz(s);
	}
	printf(bad*2 < N ? "Boris\n" : "Colleague\n");
}
