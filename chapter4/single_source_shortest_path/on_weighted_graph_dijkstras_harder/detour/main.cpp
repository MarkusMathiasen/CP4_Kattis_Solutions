#include <bits/stdc++.h>

using namespace std;

#define ii pair<ll, ll>
#define iii pair<ll, ii>
#define ll long long

ll n, m;
vector<vector<ii>> graph;
vector<bool> vis;
priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> Q;
vector<ll> path;

bool dfs(ll n){
    if (vis[n]) return false;
    vis[n] = true;
    if (n == 1){
        path.push_back(n);
        return true;
    }
    for (ll i = 0; i < graph[n].size(); i++){
        if (graph[n][i].first == -1) continue;
        if (dfs(graph[n][i].second)){
            path.push_back(n);
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    graph.assign(n, vector<ii>());
    for (ll i = 0; i < m; i++){
        ll v1, v2, d; cin >> v1 >> v2 >> d;
        graph[v1].push_back(ii(d, v2));
        graph[v2].push_back(ii(d, v1));
    }
    Q.push(vector<ll> {0, 1, -1});
    vis.assign(n, 0);
    while (!Q.empty()){
        ll d = Q.top()[0];          //distance
        ll n = Q.top()[1];          //node
        ll p = Q.top()[2];          //parent
        Q.pop();
        if (vis[n]) continue;
        vis[n] = true;
        for (ll i = 0; i < graph[n].size(); i++){
            if (graph[n][i].second == p)
                graph[n][i].first = -1;
            else
                Q.push(vector<ll> {d+graph[n][i].first, graph[n][i].second, n, i});
        }
    }
    vis.assign(n, 0);
    if (!dfs(0)){
        cout << "impossible" << endl;
        return 0;
    }
    cout << path.size() << " ";
    for (ll i = path.size()-1; i >=0; i--)
        cout << path[i] << " ";
    cout << endl;
}
