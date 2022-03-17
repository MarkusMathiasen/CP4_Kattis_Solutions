#include <bits/stdc++.h>
using namespace std;

const int R = 5, C = 9;
vector<string> board(R, "");

int rec() {
	int cnt = 0;
	int res = 100;
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++) {
			if (board[row][col] != 'o')
				continue;
			cnt++;
			vector<int> dr = {1, -1, 0, 0};
			vector<int> dc = {0, 0, 1, -1};
			for (int d = 0; d < 4; d++) {
				int r1 = row+dr[d], r2 = r1+dr[d];
				int c1 = col+dc[d], c2 = c1+dc[d];
				if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C)
					continue;
				if (board[r1][c1] == 'o' && board[r2][c2] == '.') {
					board[r1][c1] = board[row][col] = '.';
					board[r2][c2] = 'o';
					res = min(res, rec());
					board[row][col] = board[r1][c1] = 'o';
					board[r2][c2] = '.';
				}
			}
		}
	return min(cnt, res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		getline(cin, board[0]);
		for (int i = 0; i < R; i++)
			getline(cin, board[i]);
		int before = 0;
		for (string& s : board)
			for (char c : s)
				before += c == 'o';
		int after = rec();
		printf("%d %d\n", after, before-after);
	}
}
