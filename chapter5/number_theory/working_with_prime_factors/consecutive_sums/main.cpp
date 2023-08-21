#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ll a = -1, b = -1;
		for (ll t = 2; t*t <= 2*n; t++)
			if ((2*n)%t == 0 && (2*n/t-t+1)%2 == 0) {
				a = (2*n/t-t+1)/2;
				b = t;
				break;
			}
		if (a == -1) printf("IMPOSSIBLE\n");
		else {
			printf("%lld = %lld", n, a);
			rep(i, 1, b) printf(" + %lld", a + i);
			printf("\n");
		}
	}
}
