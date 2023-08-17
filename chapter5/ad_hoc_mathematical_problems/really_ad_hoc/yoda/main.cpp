#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ton(string s) {
	int res = 0;
	bool yoda = true;
	for (char c : s) {
		if (c != ' ') {
			yoda = false;
			res *= 10;
			res += c-'0';
		}
	}
	return yoda ? -1 : res;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b; cin >> a >> b;
	rep(i, 0, min(sz(a), sz(b))) {
		int ia = sz(a)-1-i, ib = sz(b)-1-i;
		if (a[ia] < b[ib])
			a[ia] = ' ';
		else if (b [ib] < a[ia])
			b[ib] = ' ';
	}
	int x = ton(a);
	int y = ton(b);
	if (x == -1) printf("YODA\n");
	else printf("%d\n", x);
	if (y == -1) printf("YODA\n");
	else printf("%d\n", y);
}
