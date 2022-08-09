#include <bits/stdc++.h>
using namespace std;

int n, m;
int heads[20000], knights[20000];

int main() {
	while (scanf("%d%d", &n, &m), n|m) {
		for (int i = 0; i < n; i++)
			scanf("%d", heads+i);
		for (int i = 0; i < m; i++)
			scanf("%d", knights+i);
		sort(heads, heads+n);
		sort(knights, knights+m);
		int h = 0, res = 0;
		for (int k = 0; k < m && h < n; k++)
			if (knights[k] >= heads[h])
				h++,
				res += knights[k];
		if (h < n)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", res);
	}
}
