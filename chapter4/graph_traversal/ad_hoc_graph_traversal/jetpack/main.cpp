#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vector<string> grid(10, "");
vector<vi> p; // 1 = held; -1 = released; 0 = unreachable

void print_p() {
	rep(i, 0, 10) {
		rep(j, 0, N) printf("%2d ", p[9-i][j]);
		printf("\n");
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, 10) cin >> grid[9-i];
	p.assign(10, vi(N, 0));
	p[0][0] = -1;
	rep(w, 1, N) rep(h, 0, 10) {
		if (grid[h][w] == 'X') continue;
		else if (h < 9 && p[h+1][w-1]) p[h][w] = -1;	// normal fall
		else if (h == 0 && p[h][w-1]) p[h][w] = -1; // stay on ground
		else if (h > 0 && p[h-1][w-1]) p[h][w] = 1; // normal ascend
		else if (h == 9 && p[h][w-1]) p[h][w] = 1; 	// stay on ceiling
	}
	vector<pii> moves;
	int h = -1, w = N-1;
	rep(i, 0, 10) if (p[i][w]) h = i;
	int held = 0;
	while (w >= 0) {
		if (p[h][w] == 1){
			held++;
			if (p[h-1][w-1]) h--;
			else
				assert(h == 9);
		}
		else if (p[h][w] == -1) {
			if (held) {
				moves.push_back({w, held});
				held = 0;
			}
			if (w && p[h+1][w-1]) h++;
			else assert(h == 0);
		} else assert(false);
		w--;
	}
	printf("%d\n", sz(moves));
	for (int i = sz(moves)-1; i >= 0; i--)
		printf("%d %d\n", moves[i].first, moves[i].second);
}
