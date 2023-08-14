#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, t, a, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld %lld/%lld", &t, &a, &b);
		printf("%lld ", t);
		if (b == 1) {
			printf("%lld/%lld\n", 1ll, a+1);
			continue;
		}
		ll cnt = 0;
		cnt = a/b;
		a %= b; // go up to the left a bunch
		b -= a; // go up to the right once
		a += b; // go down to the right
		b += a*cnt; // go down to the left a bunch
		printf("%lld/%lld\n", a, b);
	}
}
