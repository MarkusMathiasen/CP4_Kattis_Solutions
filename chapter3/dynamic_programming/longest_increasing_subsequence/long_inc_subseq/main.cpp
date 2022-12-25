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
    int N; while (scanf("%d", &N) == 1) {
        vi A(N); rep(i, 0, N) scanf("%d", &A[i]);
        vi p(N), L(N), L_id(N);
        int k = 0, end = -1;
        rep(i, 0, N) {
            ll pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
            L[pos] = A[i];
            L_id[pos] = i;
            p[i] = pos == 0 ? -1 : L_id[pos-1];
            if (pos == k) k++;
            if (pos+1 == k) end = i;
        }
        printf("%d\n", k);
        stack<int> res;
        while (end != -1) {
            res.push(end);
            end = p[end];
        }
        while (!res.empty())
            printf("%d ", res.top()), res.pop();
        printf("\n");
    }
}
