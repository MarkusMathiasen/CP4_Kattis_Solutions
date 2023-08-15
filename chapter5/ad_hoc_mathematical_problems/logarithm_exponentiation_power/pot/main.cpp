#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int res = 0;
    while (N--) {
        int x; cin >> x;
        res += (int)round(pow(x/10, x%10));
    }
    cout << res << endl;
}
