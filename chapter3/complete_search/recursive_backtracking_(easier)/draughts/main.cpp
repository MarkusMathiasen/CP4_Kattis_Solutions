#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char board[N][N];

int rec(int row, int col) {
	int res = 0;
	for (int dx : {-1, 1})
		for (int dy : {-1, 1}) {
			if (row+2*dy < 0 || row+2*dy > 9 || col+2*dx < 0 || col+2*dx > 9)
				continue;
			if (board[row+dy][col+dx] != 'B' || board[row+2*dy][col+2*dx] != '#')
				continue;
			board[row][col] = board[row+dy][col+dx] = '#';
			board[row+2*dy][col+2*dx] = 'W';
			res = max(res, 1+rec(row+2*dy, col+2*dx));
			board[row+2*dy][col+2*dx] = '#';
			board[row][col] = 'W';
			board[row+dy][col+dx] = 'B';
		}
	return res;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int res = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf(" %c", &board[i][j]);
		for (int row = 0; row < N; row++)
			for (int col = (row+1)%2; col < N; col++)
				if (board[row][col] == 'W')
					res = max(res, rec(row, col));
		printf("%d\n", res);
	}
}
