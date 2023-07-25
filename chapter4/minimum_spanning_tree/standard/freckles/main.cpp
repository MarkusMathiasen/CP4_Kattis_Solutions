#include <bits/stdc++.h>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b){
    double dx = a.first-b.first;
    double dy = a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    int T; cin >> T;
    while (T--){
        int nodeCount; cin >> nodeCount;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
        vector<pair<double, double>> nodes(nodeCount, pair<double, double> ());
        for (int i = 0; i < nodeCount; i++){
            double x, y; cin >> x >> y;
            nodes[i] = make_pair(x, y);
        }
        vector<bool> vis(nodeCount, 0);
        Q.push(make_pair(0.0, 0));
        double L = 0;
        while (!Q.empty()){
            pair<double, int> state = Q.top();
            Q.pop();
            if (vis[state.second]) continue;
            vis[state.second] = true;
            L += state.first;
            for (int i = 0; i < nodeCount; i++){
                Q.push(make_pair(dist(nodes[i], nodes[state.second]), i));
            }
        }
        cout << setprecision(2) << fixed << L << endl;
    }
}
