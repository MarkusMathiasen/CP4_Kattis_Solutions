#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, T;
vector<vector<int>> persons;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int N, T;
    scanf("%d%d", &N, &T);
    persons.assign(T, vector<int>());
    rep(i, 0, N) {
        int c, t;
        scanf("%d%d", &c, &t);
        persons[t].push_back(c);
    }
    int res = 0;
    priority_queue<int> pq;
    for (int t = T-1; t >= 0; t--) {
        for (int c : persons[t]) pq.push(c);
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    printf("%d\n", res);
}
