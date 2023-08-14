#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T;

bool arith(vi& A) {
	int diff = A[1]-A[0];
	rep(i, 0, sz(A)-1)
		if (A[i+1]-A[i] != diff)
			return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		int n; cin >> n;
		vi A(n, 0);
		rep(i, 0, n) cin >> A[i];
		if (arith(A)) {
			printf("arithmetic\n");
			continue;
		}
		sort(all(A));
		if (arith(A))
			printf("permuted arithmetic\n");
		else
			printf("non-arithmetic\n");
	}
}
