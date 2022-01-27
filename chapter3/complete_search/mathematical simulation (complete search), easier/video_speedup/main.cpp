#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, k; scanf("%d%d%d", &n, &p, &k);
	vector<int> t(n+2, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i+1]);
	t[n+1] = k;
	double res = 0;
	for (int i = 1; i <= n+1; i++)
		res += (100+(i-1)*p)*(t[i]-t[i-1])/100.0;
	printf("%lf\n", res);
}
