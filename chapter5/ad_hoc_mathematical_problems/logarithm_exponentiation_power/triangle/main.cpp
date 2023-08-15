#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t = 0;
long double n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		/*long double real_N = pow(3, n);
		long double real_s = pow(0.5, n);
		long double log_N = log10(real_N);
		long double log_s = log10(real_s);*/
		long double N = n*log10(3);
		long double s = n*(-log10(2));
		long long res = (ll)floor(1+N+s+log10(3));
		printf("Case %d: %lld\n", ++t, res);
	}

}
