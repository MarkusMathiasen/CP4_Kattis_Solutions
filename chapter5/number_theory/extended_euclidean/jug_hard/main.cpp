#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, a, b, d;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> d;
		if (d % gcd(a, b) == 0) printf("Yes\n");
		else printf("No\n");
	}
}
