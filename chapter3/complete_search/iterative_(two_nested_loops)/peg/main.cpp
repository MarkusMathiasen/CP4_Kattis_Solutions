#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> board(9, "         ");
	for (int i = 1; i <= 7; i++) {
		string s; getline(cin, s);
		board[i] = " " + s + " ";
	}
	int res = 0;
	for (int i = 1; i <= 7; i++)
		for (int j = 1; j <= 7; j++)
			if (board[i][j] == 'o')
				res += board[i-1][j] == '.' && board[i+1][j] == 'o',
				res += board[i+1][j] == '.' && board[i-1][j] == 'o',
				res += board[i][j-1] == '.' && board[i][j+1] == 'o',
				res += board[i][j+1] == '.' && board[i][j-1] == 'o';
	printf("%d\n", res);
}
