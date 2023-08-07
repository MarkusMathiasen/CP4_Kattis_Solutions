#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, dist[26][26];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n;
	rep(i, 0, 26) dist[i][i] = 1;
	while (m--) {
		char a, b; cin >> a >> b;
		dist[a-'a'][b-'a'] = 1;
	}
	rep(k, 0, 26) rep(i, 0, 26) rep(j, 0, 26)
		dist[i][j] |= dist[i][k]&dist[k][j];
	while (n--) {
		string a, b; cin >> a >> b;
		if (sz(a) != sz(b)) {
			printf("no\n");
			continue;
		}
		bool res = true;
		rep(i, 0, sz(a)) res &= dist[a[i]-'a'][b[i]-'a'];
		if (res) printf("yes\n");
		else printf("no\n");
	}
}
