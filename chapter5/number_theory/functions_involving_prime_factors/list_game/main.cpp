#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, res = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (ll i = 2; i*i <= n; i++) {
		while (n%i == 0)
			res++,
			n /= i;
	}
	if (n > 1) res++;
	printf("%lld\n", res);
}
