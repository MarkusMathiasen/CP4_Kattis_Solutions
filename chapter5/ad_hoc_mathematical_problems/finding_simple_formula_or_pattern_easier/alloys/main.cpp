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
	cin >> n;
	n = min(n, 1.0L);
	printf("%Lf\n", (n/2)*(n/2));
}
