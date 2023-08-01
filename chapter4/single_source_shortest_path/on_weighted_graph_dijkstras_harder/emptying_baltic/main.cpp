#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define iii pair<int, pair<int, int>>

vector<vector<int>> grid;
vector<vector<bool>> vis;
int a, b;
priority_queue<iii, vector<iii>, greater<iii>> Q;

int main(){
    int H, B; cin >> H >> B;
    grid.assign(H, vector<int>(B, 0));
    vis.assign(H, vector<bool>(B, 0));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < B; j++)
            cin >> grid[i][j];
    cin >> a >> b; a--; b--;
    long long result = 0;
    Q.push(iii(grid[a][b], ii(a, b)));
    while(!Q.empty()){
        iii state = Q.top();
        Q.pop();
        int x = state.second.first;
        int y = state.second.second;
        int h = state.first;
        if (vis[x][y]) continue;
        vis[x][y] = true;
        if (grid[x][y] >= 0) continue;
        h = max(h, grid[x][y]); result += h;
        if (x > 0 && y > 0) Q.push(iii(h, ii(x-1, y-1)));   //SV
        if (x > 0) Q.push(iii(h, ii(x-1, y)));              //V
        if (x > 0 && y < B-1) Q.push(iii(h, ii(x-1, y+1))); //NV
        if (y < B-1) Q.push(iii(h, ii(x, y+1)));            //N
        if (x < H-1 && y < B-1) Q.push(iii(h, ii(x+1, y+1)));   //NØ
        if (x < H-1) Q.push(iii(h, ii(x+1, y)));            //Ø
        if (x < H-1 && y > 0) Q.push(iii(h, ii(x+1, y-1))); //SØ
        if (y > 0) Q.push(iii(h, ii(x, y-1)));              //S
    }
    cout << -result << endl;
}
