#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll T, x, y;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> x >> y;
		ll L = lcm(x-1, y-1);
		ll res = L+1;
		res += (-L/(x-1)*L/(y-1) + L/(x-1) + L/(y-1) - 1)/2;
		printf("%lld\n", res);
	}
}
