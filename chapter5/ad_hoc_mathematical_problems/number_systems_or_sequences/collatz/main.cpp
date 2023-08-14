#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll a, b, c;
unordered_map<ll,ll> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> a >> b), a || b) {
		ll ca = a, cb = b;
		ll as = 0, bs = 0;
		m.clear();
		while (a != 1)
			m[a] = as++,
			a = a%2 ? 3*a+1 : a/2;
		m[1] = as;
		while (b != 1) {
			if (m.count(b)) break;
			b = b%2 ? 3*b+1 : b/2;
			bs++;
		}
		printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", ca, m[b], cb, bs, b);
	}
}
