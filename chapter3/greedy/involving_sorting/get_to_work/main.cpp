#include <bits/stdc++.h>
using namespace std;

int main() {
	int C; scanf("%d", &C);
	for (int c = 1; c <= C; c++) {
		int N, T, E; scanf("%d%d%d", &N, &T, &E); T--;
		vector<vector<int>> towns(N, vector<int>());
		while (E--) {
			int H, P; scanf("%d%d", &H, &P); H--;
			towns[H].push_back(P);
		}
		bool possible = true;
		vector<int> res(N, 0);
		for (int t = 0; t < N; t++) {
			if (t == T)
				continue;
			sort(towns[t].rbegin(), towns[t].rend());
			int p = 0, i = 0;
			while (p < (int)towns[t].size()) {
				if (!towns[t][i]) {
					possible = false;
					break;
				}
				p += towns[t][i++];
			}
			res[t] = i;
		}
		printf("Case #%d:", c);
		if (!possible)
			printf(" IMPOSSIBLE");
		else
			for (int x : res)
				printf(" %d", x);
		printf("\n");
	}
}
