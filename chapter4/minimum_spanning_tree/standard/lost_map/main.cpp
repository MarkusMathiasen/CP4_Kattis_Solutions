#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2500;

struct path {
    int a, b;
    long long d;
};

int uf[MAX_N], n;
path paths[MAX_N*MAX_N];

int find(int x) {
    if (uf[x] == x)
        return x;
    return uf[x] = find(uf[x]);
}

int main() {
    scanf("%d", &n);
    for (int a = 0; a < n; a++) {
        uf[a] = a;
        for (int b = 0; b < n; b++) {
            paths[a*n+b].a = a;
            paths[a*n+b].b = b;
            scanf("%lld", &paths[a*n+b].d);
        }
    }
    sort(paths, paths+n*n, [](const path& a, const path& b) {
        return a.d < b.d;
    });
    for (int i = 0; i < n*n; i++) {
        int x = find(paths[i].a);
        int y = find(paths[i].b);
        if (x != y) {
            uf[x] = y;
            printf("%d %d\n", paths[i].a+1, paths[i].b+1);
        }
    }
}
