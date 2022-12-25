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
	int N; while (cin >> N && N) {
        vi A(N); rep(i, 0, N) cin >> A[i];
        vi p(N), L(N), L_id(N);
        int k = 0, end = 0;
        rep(i, 0, N) {
            int pos = (int)(lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin());
            L[pos] = A[i];
            L_id[pos] = i;
            p[i] = pos == 0 ? -1 : L_id[pos-1];
            if (pos == k)
                k++;
            if (pos+1 == k)
                end = i;
        }
        printf("%d", k);
        stack<int> res;
        while (end != -1) {
            res.push(A[end]);
            end = p[end];
        }
        while (!res.empty())
            printf(" %d", res.top()),
            res.pop();
        printf("\n");
    }
}
