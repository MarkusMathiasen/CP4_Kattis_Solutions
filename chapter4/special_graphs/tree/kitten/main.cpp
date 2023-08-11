#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int K; cin >> K;
    unordered_map<int, int> p;
    string line; while (getline(cin, line), line != "-1") {
        stringstream ss(line);
        int x, y; ss >> x;
        while (ss >> y) p[y] = x;
    }
    printf("%d", K);
    while (p.count(K)) K = p[K], printf(" %d", K);
    printf("\n");
}
