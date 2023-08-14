#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int d, r, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> d >> r >> t;
	// R*(R+1)/2 - 6
	int age;
	rep(R, 4, 1000) {
		int T = R-d;
		int sum = R*(R+1)/2-6 + T*(T+1)/2-3;
		if (sum == r+t) {
			age = R;
			break;
		}
	}
	printf("%d\n", r-(age*(age+1)/2-6));
}
