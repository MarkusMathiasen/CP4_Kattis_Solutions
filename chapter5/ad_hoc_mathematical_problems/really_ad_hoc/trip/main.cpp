#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, sum;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (scanf("%d", &n), n) {
		A.assign(n, 0);
		sum = 0;
		rep(i, 0, n) {
			int a, b; scanf("%d.%d\n", &a, &b);
			a = a*100+b;
			A[i] = a;
			sum += a;
		}
		int am = sum/n;
		int rem = sum%n;
		int res = 0;
		for (int x : A) {
			if (x > am) {
				res += x-am;
				if (rem) {
					res--;
					rem--;
				}
			}
		}
		printf("$%d.%02d\n", res/100, res%100);
	}
}
