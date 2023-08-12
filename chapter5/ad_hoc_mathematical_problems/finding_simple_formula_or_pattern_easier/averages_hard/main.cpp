#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n, m, sn, sm;
vi An, Am;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		sn = sm = 0;
		An.assign(n, 0);
		Am.assign(m, 0);
		rep(i, 0, n) {
			cin >> An[i];
			sn += An[i];
		}
		rep(i, 0, m) {
			cin >> Am[i];
			sm += Am[i];
		}
		ll res = 0;
		rep(i, 0, n)
			if (An[i] < sn/n || (An[i] == sn/n && sn%n))
				if (An[i] > sm/m)
					res++;
		printf("%lld\n", res);
	}
}
