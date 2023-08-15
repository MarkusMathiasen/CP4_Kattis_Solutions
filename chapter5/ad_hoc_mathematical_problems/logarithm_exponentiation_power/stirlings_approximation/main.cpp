#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long double n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		long double log_fac = 0;
		rep(i, 1, n+1) log_fac += log(i);
		long double log_s = log(2*M_PI*n)/2+n*log(n)-n;
		printf("%.8Lf\n", exp(log_fac-log_s));
	}
}
