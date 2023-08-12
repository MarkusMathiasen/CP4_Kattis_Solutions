#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll X, Y, N;
double r;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> X >> Y >> N >> r), X || Y || N || r) {
		N *= 12;
		double left;
		if (r == 0)
			left = (double)(X-N*Y);
		else {
			r = r/1200+1;
			double r_pow = pow(r, N);
			left = (double)X*r_pow - (double)Y*(1-r_pow)/(1-r);
		}
		if (left <= 0) printf("YES\n");
		else printf("NO\n");
	}
}
