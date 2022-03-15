#include <bits/stdc++.h>
using namespace std;

map<string, int> color_to_int;
vector<vector<bool>> hid;
vector<bool> used;
vector<string> colors;
int T, n, m, cnt;
vector<int> res, track;

void dfs(int depth) {
	if (depth == n) {
		if (!cnt)
			res = track;
		cnt++;
		return;
	}
	for (int color = 1; color <= n; color++) {
		if (used[color] || hid[color][track.back()])
			continue;
		track.push_back(color);
		used[color] = true;
		dfs(depth+1);
		used[color] = false;
		track.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		colors.assign(n+1, "");
		color_to_int.clear();
		for (int i = 1; i <= n; i++) {
			cin >> colors[i];
			color_to_int[colors[i]] = i;
		}
		cin >> m;
		hid.assign(n+1, vector<bool>(n+1, false));
		while (m--) {
			string c1, c2; cin >> c1 >> c2;
			int n1 = color_to_int[c1];
			int n2 = color_to_int[c2];
			hid[n1][n2] = hid[n2][n1] = true;
		}
		cnt = 0;
		res.clear(); track = {0};
		used.assign(n+1, false);
		dfs(0);
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
			printf("%s ", colors[res[i]].c_str());
		printf("\n");
	}
}
