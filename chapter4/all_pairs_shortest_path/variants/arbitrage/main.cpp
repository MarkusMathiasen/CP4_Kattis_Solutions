#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vector<double>> A;
unordered_map<string, int> toi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
start:
	while ((cin >> n), n) {
		A.assign(n, vector<double>(n, 0));
		rep(i, 0, n) A[i][i] = 1;
		toi.clear();
		rep(i, 0, n) {
			string s; cin >> s; toi[s] = i;
		}
		cin >> m;
		while (m--) {
			string s1, s2; cin >> s1 >> s2;
			int a = toi[s1], b = toi[s2];
			string s; cin >> s;
			double x, y; sscanf(s.c_str(), "%lf:%lf", &x, &y);
			A[a][b] = y/x;
		}
		rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
			A[i][j] = max(A[i][j], A[i][k]*A[k][j]);
		rep(i, 0, n) if (A[i][i] > 1.0l){
			printf("Arbitrage\n");
			goto start;
		}
		printf("Ok\n");
	}
}
