#include <bits/stdc++.h>
using namespace std;

int tasks[200000], intervals[200000];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", tasks+i);
	for (int i = 0; i < m; i++)
		scanf("%d", intervals+i);
	sort(tasks, tasks+n);
	sort(intervals, intervals+m);
	int i = 0, res = 0;
	for (int t = 0; t < n; t++) {
		while (i < m && tasks[t] > intervals[i])
			i++;
		if (i >= m)
			break;
		res++, i++;
	}
	printf("%d\n", res);
}
