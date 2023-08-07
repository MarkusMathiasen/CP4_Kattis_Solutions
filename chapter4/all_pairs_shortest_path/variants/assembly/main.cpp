#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 52;

int n;
int dist[N][N];

int toi(char a, char b) {
	return (a-'A')*2+(b=='+');
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	while (n--) {
		string s; cin >> s;
		rep(i, 0, 4) rep(j, i+1, 4) {
			char a1 = s[i*2], a2 = s[i*2+1];
			char b1 = s[j*2], b2 = s[j*2+1];
			if (a1 == '0' || b1 == '0') continue;
			int a = toi(a1, a2);
			int b = toi(b1, b2);
			if (a%2) dist[a-1][b] = 1;
			else dist[a+1][b] = 1;
			if (b%2) dist[b-1][a] = 1;
			else dist[b+1][a] = 1;
		}
	}
	rep(k, 0, N) rep(i, 0, N) rep(j, 0, N)
		dist[i][j] |= dist[i][k] & dist[k][j];
	bool res = false;
	rep(i, 0, N) res |= dist[i][i];
	if (res) printf("unbounded\n");
	else printf("bounded\n");
}
