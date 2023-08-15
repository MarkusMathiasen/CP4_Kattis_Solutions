#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
string line, res;

bool special(char c) {
	return ('!' <= c && c <= '*') || ('[' <= c && c <= ']');
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		getline(cin, line); getline(cin, line);
		res = "";
		for (char c : line) {
			if (special(c)) rep(i, 1, 1<<n) res.push_back('\\');
			res.push_back(c);
		}
		printf("%s\n", res.c_str());
	}
}
