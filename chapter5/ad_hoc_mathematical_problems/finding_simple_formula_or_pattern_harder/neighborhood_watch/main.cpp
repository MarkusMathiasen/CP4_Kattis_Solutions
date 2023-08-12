#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	A.assign(n, 0);
	while (k--) {
		int a; cin >> a; a--;
		A[a] = 1;
	}
	int last = -1;
	ll res = 0;
	rep(i, 0, n) {
		if (A[i]) last = i;
		res += last+1;
	}
	printf("%lld\n", res);
}
