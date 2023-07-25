#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, H, W;
vector<string> grid;

bool is_dot(int x, int y) {
	if (x < 0 || x > H || y < 0 || y >= W) return true;
	return grid[x][y] == '.';
}

int main() {
	scanf("%d", &N);
	vector<tuple<int, int, int>> builds;
	int min_x = 1e9, max_x = 0, max_h = 0;
	rep(i, 0, N) {
		int l, r, h; scanf("%d%d%d", &l, &r, &h);
		l++;
		min_x = min(min_x, l);
		max_x = max(max_x, r);
		max_h = max(h, max_h);
		builds.push_back({l, r, h});
	}
	H = max_h;
	W = max_x - min_x + 1;
	for (auto& [l,r,h] : builds) {
		l -= min_x;
		r -= min_x;
	}
	sort(all(builds));
	queue<tuple<int, int, int>> q;
	rep(i, 0, N) q.push(builds[i]);
	grid.assign(H+1, string(W, '.'));
	priority_queue<pii> pq; //height, end
	int w = -1, h = 0;
	while (++w < W) {
		if (!q.empty()) {
			while (w == get<0>(q.front())) {
				pq.push({get<2>(q.front()), get<1>(q.front())});
				q.pop();
			}
		}
		while (pq.size() && pq.top().second < w)
			pq.pop();
		int cur_h = pq.empty() ? 0 : pq.top().first;
		while (cur_h < h)
			grid[--h][w-1] = '#';
		while (cur_h > h)
			grid[h++][w] = '#';
		grid[h][w] = '#';
	}
	// last line
	rep(i, 0, H+1) {
		if (grid[i][W-1] == '#')
			break;
		grid[i][W-1] = '#';
	}
	rep(i, 0, W) grid[0][i] = '*';
	// count perimeter
	int per = 0;
	rep(i, 0, H+1) rep(j, 0, W) {
		if (grid[i][j] != '#') continue;
		per += is_dot(i+1, j);
		per += (is_dot(i+1, j) + is_dot(i, j+1) + is_dot(i, j-1))/2;
	}
	printf("%d\n", per);
	for (int i = H; i >= 0; i--)
		printf("%s\n", grid[i].c_str());
}
