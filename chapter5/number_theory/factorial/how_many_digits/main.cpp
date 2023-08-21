#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi res = {1};

int main() {
	double log_sum = 0;
	rep(i, 1, 1e6+1) {
		log_sum += log10(i);
		res.push_back((int)floor(log_sum)+1);
	}
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n)
		printf("%d\n", res[n]);
}
