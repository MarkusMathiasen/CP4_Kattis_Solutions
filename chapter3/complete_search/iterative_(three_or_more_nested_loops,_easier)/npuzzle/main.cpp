#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board(4, vector<char>(4, ' '));

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf(" %c", &board[i][j]);
	int res = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == '.')
				continue;
			int row = (board[i][j]-'A')/4;
			int col = (board[i][j]-'A')%4;
			res += abs(row-i) + abs(col-j);
		}
	printf("%d\n", res);
}
