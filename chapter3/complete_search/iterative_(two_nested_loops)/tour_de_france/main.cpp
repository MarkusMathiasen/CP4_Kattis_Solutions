#include <bits/stdc++.h>
using namespace std;

int main() {
	int F, R;
	while (scanf("%d%d", &F, &R) && F != 0) {
		vector<int> front(F, 0);
		vector<double> gears;
		for (int i = 0; i < F; i++)
			scanf("%d", &front[i]);
		for (int i = 0; i < R; i++) {
			int r; scanf("%d", &r);
			for (int f : front)
				gears.push_back(r / (double)f);
		}
		sort(gears.begin(), gears.end());
		double res = 0;
		for (int i = 0; i < R*F-1; i++)
			res = max(res, gears[i+1]/gears[i]);
		printf("%.2lf\n", res);
	}
}
