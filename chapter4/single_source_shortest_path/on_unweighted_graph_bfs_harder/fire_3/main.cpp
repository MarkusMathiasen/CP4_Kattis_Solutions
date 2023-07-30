#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> grid;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void print_grid(vector<vi>& grid) {
    rep(i, 0, sz(grid)) {
        rep(j, 0, sz(grid[i]))
            printf("%3d ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    grid.assign(n, "");
    rep(i, 0, n) cin >> grid[i];
    queue<pii> q;
    int sx, sy;
    vector<vi> fire(n, vi(m, -1));
    rep(i, 0, n) rep(j, 0, m) {
        if (grid[i][j] == 'J') sx = i, sy = j;
        else if (grid[i][j] == 'F') {
            q.push({i, j});
            fire[i][j] = 0;
        }
    }
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        rep(i, 0, 4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#' || fire[nx][ny] != -1) continue;
            fire[nx][ny] = fire[x][y]+1;
            q.push({nx, ny});
        }
    }
    q.push({sx, sy});
    vector<vi> dist(n, vi(m, -1));
    dist[sx][sy] = 0;
    int res = -1;
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        rep(i, 0, 4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                res = dist[x][y]+1;
                goto end;
            }
            if (grid[nx][ny] == '#' || dist[nx][ny] != -1)
                continue;
            if (fire[nx][ny] != -1 && dist[x][y]+1 >= fire[nx][ny])
                continue;
            dist[nx][ny] = dist[x][y]+1;
            q.push({nx, ny});
        }
    }
end:
    if (res == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", res);

}
