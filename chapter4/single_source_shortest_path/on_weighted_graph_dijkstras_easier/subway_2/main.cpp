#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define dii pair<double, ii>

priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> Q;
// først minutter gået, derefter (station, stop)

pair<int, int> home, goal;
vector<vector<pair<int, int>>> subways;
const double walkSpeed = (double)1000*10/60;
const double subSpeed = (double)1000*40/60;

double walkTime(pair<int, int> a, pair<int, int> b){
    double dx = (double)a.first - b.first;
    double dy = (double)a.second - b.second;
    double dist = sqrt(dx*dx+dy*dy);
    return dist / walkSpeed;
}
double subTime(pair<int, int> a, pair<int, int> b){
    double dx = (double)a.first - b.first;
    double dy = (double)a.second - b.second;
    double dist = sqrt(dx*dx+dy*dy);
    return dist / subSpeed;
}

int main(){
    int x, y; cin >> x >> y; home = make_pair(x, y);
    cin >> x >> y; goal = make_pair(x, y);
    int subCount = 0;
    subways.push_back(vector<pair<int, int>>());
    while(cin >> x >> y){
        if (x == -1){
            subCount++;
            subways.push_back(vector<pair<int, int>>());
            continue;
        }
        subways[subCount].push_back(make_pair(x, y));
    }
    subways.pop_back(); subCount++;
    vector<vector<double>> vis(subCount, vector<double>());
    for (int i = 0; i < subCount; i++)
        vis[i].assign(subways[i].size(), 0);
    for (int i = 0; i < subCount; i++){
        for (int j = 0; j < subways[i].size(); j++){
            Q.push(pair<double, pair<int, int>>(walkTime(home, subways[i][j]), make_pair(i, j)));
        }
    }
    Q.push(pair<double, pair<int, int>>(walkTime(home, goal), make_pair(-1, -1)));
    double result = 2000000000;
    while(true){
        pair<double, pair<int, int>> state = Q.top();
        Q.pop();
        double time = state.first;
        int line = state.second.first;
        int stop = state.second.second;
        if (line == -1){result = time; break;}
        if (vis[line][stop]) continue;
        vis[line][stop] = time;
        for (int i = 0; i < subCount; i++)
            for (int j = 0; j < subways[i].size(); j++)
                Q.push(dii(time+walkTime(subways[line][stop], subways[i][j]), ii(i, j)));
        Q.push(dii(time+walkTime(subways[line][stop], goal), ii(-1, -1)));
        if (stop+1 < subways[line].size()) Q.push(dii(time+subTime(subways[line][stop], subways[line][stop+1]), ii(line, stop+1)));
        if (stop > 0) Q.push(dii(time+subTime(subways[line][stop], subways[line][stop-1]), ii(line, stop-1)));
    }
    cout << round(result) << endl;
}
