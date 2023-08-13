#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		rep(a, 0, n+1) {
			if (ceil(log10(7)*a + log10(11)*(n-a)) == n) {
				rep(i, 0, a) printf("%d ", 7);
				rep(i, a, n) printf("%d ", 11);
				printf("\n");
				break;
			}
		}
	}
}
