#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<long double, long double> pdd;
typedef vector<int> vi;

const long double MAX_DIST = 1e18;
const long double EPS = 1e-12;

int n, k;
map<string, int> m;
vector<string> m2;
map<string, pdd> points;
vector<vector<long double>> dp;
vector<vector<int>> pre;

long double dist(pdd a, pdd b) {
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

long double calc(int mask, int v) {
	if (dp[mask][v] != -1)
		return dp[mask][v];
	int mask2 = mask - (1 << v);
	long double res = MAX_DIST;
	rep(i, 0, k)
		if ((1 << i) & mask2) {
			long double sub_dist = calc(mask2, i) + dist(points[m2[v]], points[m2[i]]);
			if (sub_dist < res) {
				res = sub_dist;
				pre[mask][v] = i;
			}
		}
	return dp[mask][v] = res;
}

void get_path(vector<int>& path) {
	int mask = (1 << k) - 1;
	int v = k-1;
	while (true) {
		int pre_v = pre[mask][v];
		if (pre_v == -1) break;
		path.push_back(pre_v);
		mask -= (1 << v);
		v = pre_v;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n;
	string line; getline(cin, line);
	rep(i, 0, n) {
		getline(cin, line);
		stringstream ss(line);
		string s; long double x, y; ss >> s >> x >> y;
		points[s] = pdd(x, y);
	}
	while (getline(cin, line)) {
		m.clear(); m2.clear(); dp.clear(); pre.clear();
		//m["home"] = n-1; m2[n-1] = "home";
		stringstream ss(line);
		string s;
		while (ss >> s) {
			m[s] = sz(m2);
			m2.push_back(s);
		}
		m["home"] = sz(m2); m2.push_back("home");
		k = sz(m2);
		vector<int> res;
		dp.assign(1 << k, vector<long double>(k, -1));
		pre.assign(1 << k, vector<int>(k, -1));
		rep(i, 0, k) dp[1 << i][i] = dist(points[m2[i]], points["work"]);
		calc((1 << k)-1, k-1);
		get_path(res);
		// Print result
		for (int i = sz(res)-1; i >= 0; i--)
			printf("%s ", m2[res[i]].c_str());
		printf("\n");
	}
}
