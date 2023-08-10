#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s, s1, s2;
int m, u, d;
vi price, units;
vector<string> name;
vector<vi> p;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s1 >> s2 >> d;
	int a, b; sscanf(s1.c_str(), "%d.%d", &a, &b);
	m = a*100+b;
	sscanf(s2.c_str(), "%d.%d", &a, &b);
	u = 60*a+6*b;
	rep(i, 0, d) {
		cin >> s; name.push_back(s);
		int strength; cin >> strength;
		cin >> s; sscanf(s.c_str(), "%d/%d", &a, &b);
		units.push_back(strength*6*10/b);
		cin >> s; sscanf(s.c_str(), "%d.%d", &a, &b);
		price.push_back(a*100+b);
	}
	p.assign(u+1, vi(m+1, -2));
	p[0][0] = -1;
	rep(i, 0, u) rep(j, 0, m) rep(k, 0, d)
		if (p[i][j] != -2)
			if (i+units[k] <= u && j+price[k] <= m)
				p[i+units[k]][j+price[k]] = k;
	vi cnt(d, 0);
	if (p[u][m] == -2) printf("IMPOSSIBLE\n");
	else {
		a = u, b = m;
		while (p[a][b] != -1) {
			int k = p[a][b];
			cnt[k]++;
			a -= units[k];
			b -= price[k];
		}
		rep(i, 0, d)
			if (cnt[i]) printf("%s %d\n", name[i].c_str(), cnt[i]);
	}
}
