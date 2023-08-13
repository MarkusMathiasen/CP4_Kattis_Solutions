#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll s, p, y, j, d = 12;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> s >> p >> y >> j) {
		ll Y = (d+j-p-y)/3;
		ll P = (d+j-s-Y)/2;
		ll S = (d+j-Y-P);
		printf("%lld %lld %lld\n", S, P, Y);
	}

}
