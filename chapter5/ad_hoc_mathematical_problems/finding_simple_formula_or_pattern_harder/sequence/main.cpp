#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi res;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int x = 1;
	while (x <= n)
		res.push_back(x),
		x <<= 1;
	printf("%d\n", sz(res));
	for (int x : res) printf("%d ", x);
	printf("\n");
}
