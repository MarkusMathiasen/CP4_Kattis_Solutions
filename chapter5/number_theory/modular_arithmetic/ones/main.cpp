#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		ll val = 1, res = 1;
		while (val%n != 0) {
			res++;
			val = (val*10+1)%n;
		}
		printf("%lld\n", res);
	}
}
