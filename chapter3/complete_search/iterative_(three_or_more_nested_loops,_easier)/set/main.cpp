#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<string>> board(4, vector<string>(3, ""));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	bool found = false;
	for (int a = 0; a < 12; a++)
		for (int b = a+1; b < 12; b++)
			for (int c = b+1; c < 12; c++) {
				string ca = board[a/3][a%3];
				string cb = board[b/3][b%3];
				string cc = board[c/3][c%3];
				int valid = true;
				for (int idx = 0; idx < 4; idx++) {
					if (ca[idx] == cb[idx])
						valid &= cc[idx] == cb[idx];
					else
						valid &= cc[idx] != cb[idx] && cc[idx] != ca[idx];
				}
				found |= valid;
				if (valid)
					printf("%d %d %d\n", a+1, b+1, c+1);
			}
	if (!found)
		printf("no sets\n");
}
