#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, L, n;
int A[500000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> L >> n;
		L *= 1000;
		vi low(n, 0), gap(n, 0);
		rep(i, 0, n) {
			cin >> low[i] >> gap[i];
			gap[i] -= low[i];
		}
		if (L >= 500000) {
			printf("0\n");
			continue;
		}
		memset(A, 0, sizeof(A));
		A[0] = 1;
		rep(i, 0, n) {
			int pre = 1e9;
			rep(l, 0, L+1-low[i]) {
				if (A[l]) pre=0;
				else pre++;
				if (pre <= gap[i]) A[l+low[i]] = 1;
			}
			if (A[L]) break;
		}
		int res = 1e9;
		rep(l, 0, L+1) if (A[l]) res = L-l;
		printf("%d\n", res);
	}
}
