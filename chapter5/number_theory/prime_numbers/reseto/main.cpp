#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5+1;

int n, k;
bitset<N> b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, n+1) if (b[i]) {
		for (ll j = i; j <= n; j += i) {
			if (b[j]) {
				b[j] = 0;
				k--;
				if (k == 0) {
					printf("%lld\n", j);
					return 0;
				}
			}
		}
	}
}
