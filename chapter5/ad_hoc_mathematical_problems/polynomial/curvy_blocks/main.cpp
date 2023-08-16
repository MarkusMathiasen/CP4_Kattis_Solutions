#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double b0, b1, b2, b3, t0, t1, t2, t3;
double p0, p1, p2, p3;
double a, b, c, d;
vector<double> A;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> b0 >> b1 >> b2 >> b3 >> t0 >> t1 >> t2 >> t3) {
		A = {0, 1};
		p0 = t0-b0; p1 = t1-b1; p2 = t2-b2; p3 = t3-b3;
		a = 3*p3, b = 2*p2, c = p1, d = b*b-4*a*c;
		double r1 = (-b+sqrt(d))/(2*a);
		double r2 = (-b-sqrt(d))/(2*a);
		if (0 <= r1 && r1 <= 1)
			A.push_back(r1);
		if (0 <= r2 && r2 <= 1)
			A.push_back(r2);
		double maximum = -1e9;
		double minimum = 1e9;
		for (double x : A) {
			double val = p0+p1*x+p2*x*x+p3*x*x*x;
			 maximum = max(maximum, val);
			 minimum = min(minimum, val);
		}
		printf("%.7lf\n", maximum-minimum);
	}
}
