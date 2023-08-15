#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<string, string, long double> ssd;

const long double inf = 1e18;

int n;
unordered_map<string, long double> lem;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	lem["pink"] = 0;
	rep(i, 0, n) {
		string O, W; long double r; cin >> O >> W >> r;
		if (!lem.count(W)) lem[W] = -inf;
		if (!lem.count(O)) lem[O] = -inf;
		if (lem[W] != -inf)
			lem[O] = max(lem[O], lem[W]+log2(r));
	}
	if (!lem.count("blue") || lem["blue"] == -inf)
		printf("0.0\n");
	else
		printf("%.8Lf\n", min(10.0l, pow(2, lem["blue"])));
}
