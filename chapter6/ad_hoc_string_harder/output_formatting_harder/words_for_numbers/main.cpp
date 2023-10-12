#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string s, line;

string to_long_string(ll n) {
	if (n == 0) return "zero";
	if (n == 1) return "one";
	if (n == 2) return "two";
	if (n == 3) return "three";
	if (n == 4) return "four";
	if (n == 5) return "five";
	if (n == 6) return "six";
	if (n == 7) return "seven";
	if (n == 8) return "eight";
	if (n == 9) return "nine";
	if (n == 10) return "ten";
	if (n == 11) return "eleven";
	if (n == 12) return "twelve";
	if (n == 13) return "thirteen";
	if (n == 14) return "fourteen";
	if (n == 15) return "fifteen";
	if (n == 16) return "sixteen";
	if (n == 17) return "seventeen";
	if (n == 18) return "eighteen";
	if (n == 19) return "nineteen";
	string end = to_long_string(n%10);
	if (end == "zero") end = "";
	else end = "-" + end;
	n /= 10;
	if (n == 2) return "twenty"+end;
	if (n == 3) return "thirty"+end;
	if (n == 4) return "forty"+end;
	if (n == 5) return "fifty"+end;
	if (n == 6) return "sixty"+end;
	if (n == 7) return "seventy"+end;
	if (n == 8) return "eighty"+end;
	if (n == 9) return "ninety"+end;
	assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (getline(cin, line) && line != "") {
		stringstream ss(line);
		bool first = true;
		while (ss >> s) {
			if (!first) printf(" ");
			if (isdigit(s[0])) {
				ll n = stoll(s);
				s = to_long_string(n);
				if (first) s[0] = (char)toupper(s[0]);
			}
			printf("%s", s.c_str());
			first = false;
		}
		printf("\n");
	}
}
