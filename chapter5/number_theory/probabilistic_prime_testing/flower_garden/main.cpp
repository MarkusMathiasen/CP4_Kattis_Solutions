#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T;
int n, d;

bool is_prime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x%2 == 0) return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)
			return false;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> d;
		double traveled = 0;
		int x = 0, y = 0;
		int res = 0;
		rep(i, 1, n+1) {
			int fx, fy; cin >> fx >> fy;
			traveled += hypot(x-fx, y-fy);
			x = fx, y = fy;
			if (traveled <= d && is_prime(i))
				res = i;
		}
		printf("%d\n", res);
	}

}
