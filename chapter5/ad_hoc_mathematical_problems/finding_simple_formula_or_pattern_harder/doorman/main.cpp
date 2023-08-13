#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int X;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> X >> s;
	int diff = 0, buf = 0, res = 0;
	queue<int> q;
	for (char c : s) q.push(c == 'M' ? 1 : -1);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (buf != 0 && abs(diff+buf) <= X)
			diff += buf, buf = 0, res++;
		if (abs(diff+v)	<= X)
			diff += v, res++;
		else if (buf == 0)
			buf = v;
		else break;
	}
	printf("%d\n", res);
}
