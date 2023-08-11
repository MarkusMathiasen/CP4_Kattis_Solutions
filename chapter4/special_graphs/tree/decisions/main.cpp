#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi A;

int count(int x, int i) {
	int val = -1;
	rep(k, 0, 1<<(n-i)) {
		int a = A[(x|(k<<i))];
		if (val == -1 || val == a) val = a;
		else val = 2;
	}
	if (val != 2) return 1;
	return count(x, i+1) + count(x|(1<<i), i+1) + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(1<<n, 0);
	rep(i, 0, 1<<n) cin >> A[i];
	int res = count(0, 0);
	printf("%d\n", res);
}
