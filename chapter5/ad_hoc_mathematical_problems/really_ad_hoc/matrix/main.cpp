#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a, b, c, d, t = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> a >> b >> c >> d) {
		printf("Case %d:\n", ++t);
		int det = a*d-b*c;
		printf("%d %d\n%d %d\n\n", d/det, -b/det, -c/det, a/det);
	}
}
