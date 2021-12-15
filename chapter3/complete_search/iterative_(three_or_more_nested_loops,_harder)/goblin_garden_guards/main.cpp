#include <bits/stdc++.h>
using namespace std;

const int siz = 10000;
int garden[10001][10001];

int main() {
	int g; scanf("%d", &g);
	for (int i = 0; i <= siz; i++)
		for (int j = 0; j <= siz; j++)
			garden[i][j] = 0;
	while (g--) {
		int x, y; scanf("%d%d", &x, &y);
		garden[x][y]++;
	}
	int m; scanf("%d", &m);
	while (m--) {
		int x, y, r; scanf("%d%d%d", &x, &y, &r);
		for (int i = max(x-r, 0); i <= min(x+r, siz); i++)
			for (int j = max(y-r, 0); j <= min(y+r, siz); j++)
				if ((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
					garden[i][j] = 0;
	}
	int res = 0;
	for (int i = 0; i <= siz; i++)
		for (int j = 0; j <= siz; j++)
			res += garden[i][j];
	printf("%d\n", res);
}
