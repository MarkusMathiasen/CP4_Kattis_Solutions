#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int a, b, s, m, n;
    while (scanf("%d %d %d %d %d", &a, &b, &s, &m, &n), a | b | s | m | n) {
        double dv = m*a;
        double dh = n*b;
        double d = sqrt(dv * dv + dh * dh);
        double speed = d / s;
        double A = dh > 0 ? atan(dv / (double)dh) : 90;
        A = A/(2*M_PI)*360;
        printf("%.2lf %.2lf\n", 90 - A, speed);
    }
}
