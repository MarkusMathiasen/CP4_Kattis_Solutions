#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int k;

string base_7(int x) {
	string res = "";
	while (x) {
		res.push_back((char)('0'+(x%7)));
		x /= 7;
	}
	return res;
}

string digits = "0125689";

void edit_digits(string& x) {
	for (char& c : x)
		c = digits[c-'0'];
	for (char& c : x) {
		if (c == '6') c = '9';
		else if (c == '9') c = '6';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> k) {
		string num = base_7(k);
		edit_digits(num);
		printf("%s\n", num.c_str());
	}
}
