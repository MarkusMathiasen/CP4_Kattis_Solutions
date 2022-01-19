#include <bits/stdc++.h>
using namespace std;

int n = 10, m;
vector<vector<int>> graph(n, vector<int>());
vector<string> name(n, ""), nation(n, ""), league(n, ""), team(n, "");
vector<int> players = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		cin >> name[i] >> nation[i] >> league[i] >> team[i];
	int synergy[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (nation[i] == nation[j] && team[i] == team[j])
				synergy[i][j] = synergy[j][i] = 3;
			else if (nation[i] == nation[j] && league[i] == league[j])
				synergy[i][j] = synergy[j][i] = 2;
			else if (team[i] == team[j])
				synergy[i][j] = synergy[j][i] = 2;
			else if (league[i] == league[j])
				synergy[i][j] = synergy[j][i] = 1;
			else if (nation[i] == nation[j])
				synergy[i][j] = synergy[j][i] = 1;
			else
				synergy[i][j] = synergy[j][i] = 0;
	bool found = false;
	do {
		bool valid = true;
		for (int i = 0; i < n && valid; i++) {
			int syn = 0;
			for (int j : graph[i])
				syn += synergy[players[i]][players[j]];
			valid &= syn >= (int)graph[i].size();
		}
		if (valid) {
			found = true;
			break;
		}
	} while(next_permutation(players.begin(), players.end()));
	printf(found ? "yes\n" : "no\n");
}
