#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
string s;
vector<vi> dist, p;
vector<string> tos;
unordered_map<string, int> toi;

void print_path(int i, int j) {
	if (i != j) print_path(i, p[i][j]);
	printf("%s ", tos[j].c_str());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	dist.assign(n, vi(n, 1e9));
	rep(i, 0, n) {
		cin >> s;
		tos.push_back(s);
		toi[s] = i;
	}
	rep(i, 0, n) {
		int k; cin >> s >> k;
		string line; getline(cin, line);
		while (k--) {
			string line; getline(cin, line);
			stringstream ss(line);
			ss >> s;
			while (ss >> s) {
				if (s.back() == ',') s.pop_back();
				dist[i][toi[s]] = 1;
			}
		}
	}
	p.assign(n, vi(n, -1));
	rep(i, 0, n) rep(j, 0, n)
		if (dist[i][j] == 1)
			p[i][j] = i;
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
		if (dist[i][j] > dist[i][k]+dist[k][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
			p[i][j] = p[k][j];
		}
	/* DEBUG
	rep(i, 0, n) {
		rep(j, 0, n) printf("%2d ", dist[i][j]);
		printf("\n");
	}*/
	int init = -1, best = 1e9;
	rep(i, 0, n) {
		if (dist[i][i] && dist[i][i] < best) {
			init = i;
			best = dist[i][i];
		}
	}
	if (init != -1) {
		print_path(init, p[init][init]);
		printf("\n");
	}
	else printf("SHIP IT\n");
}
