#include <bits/stdc++.h>
using namespace std;

struct shield {
	int l;
	int u;
	double f;
};

int x, y, n; 
vector<shield> shields;

double calc(double dx) {
	int yPos = 0;
	double xPos = 0;
	for (shield& s : shields) {
		xPos += dx * (s.l - yPos);
		xPos += dx * s.f * (s.u - s.l);
		yPos = s.u;
	}
	xPos += dx * (y - yPos);
	return xPos;
}

int main() {
	scanf("%d%d", &x, &y);
	scanf("%d", &n);
	shields.assign(n, shield());
	for (int i = 0; i < n; i++)
		scanf("%d%d%lf", &shields[i].l, &shields[i].u, &shields[i].f);
	sort(shields.begin(), shields.end(), [](const shield& a, const shield& b) {
		return a.l < b.l;
	});
	double low = -10, high = 10;
	while (high - low > 1e-8) {
		double mid = (low + high)/2;
		double pos = calc(mid);
		if (pos < x)
			low = mid;
		else
			high = mid;
	}
	printf("%lf\n", low);
}
