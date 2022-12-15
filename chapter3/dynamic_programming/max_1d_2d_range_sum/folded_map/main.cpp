#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int Ar, Ac, Tr, Tc;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    while (scanf("%d%d%d%d", &Ar, &Ac, &Tr, &Tc) == 4) {
        vector<vi> A(Ar+2*Tr, vi(Ac+2*Tc, 0));
        rep(i,Tr,Ar+Tr) rep(j,Tc,Ac+Tc) {
            char c; scanf(" %c", &c);
            A[i][j] = c == 'X';
        }
        vector<vi> pre_sum(A);
        rep(i,1,sz(pre_sum)) rep(j,1,sz(pre_sum[i]))
            pre_sum[i][j] += pre_sum[i][j-1] + pre_sum[i-1][j] - pre_sum[i-1][j-1];
        int res = 1e9;
        rep(sr,Tr,2*Tr) rep(sc,Tc,2*Tc) {
            int sum = 0;
            for(int i = sr; i < sz(pre_sum); i += Tr)
                for(int j = sc; j < sz(pre_sum[i]); j += Tc)
                    if (pre_sum[i][j] - pre_sum[i-Tr][j] - pre_sum[i][j-Tc] + pre_sum[i-Tr][j-Tc])
                        sum++;
            res = min(res, sum);
        }
        printf("%d\n", res);
    }
}
