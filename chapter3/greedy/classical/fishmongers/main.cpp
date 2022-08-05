#include <bits/stdc++.h>
using namespace std;

struct monger {
	int x, p;
};
bool operator<(const monger& a, const monger& b) {
	return tie(a.p, a.x) > tie(b.p, b.x);
}

int fish[100000];
monger mongers[100000];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", fish+i);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &mongers[i].x, &mongers[i].p);
	sort(fish, fish+n);
	sort(mongers, mongers+m);
	int j = 0;
	long long res = 0;
	for (int i = n-1; i >= 0; i--) {
		while (!mongers[j].x)
			j++;
		if (j >= m)
			break;
		mongers[j].x--;
		res += (long long)mongers[j].p*fish[i];
	}
	printf("%lld\n", res);
}
