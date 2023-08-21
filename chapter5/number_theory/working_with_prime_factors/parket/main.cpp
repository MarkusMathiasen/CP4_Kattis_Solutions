#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll r, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> r >> b;
	for (ll x = 1; 4*x+4 <= r; x++) {
		ll y = (r-2*x-4)/2;
		if (x*y == b) {
			printf("%lld %lld\n", y+2, x+2);
			return 0;
		}
	}
	printf("Failure!\n");
}
