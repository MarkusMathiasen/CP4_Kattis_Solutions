#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		n = n/10-194;
		double sum = 1;
		int cnt = 2;
		while (log2(sum) < n)
			sum += log2(++cnt);
		printf("%d\n", cnt-1);
	}
}
