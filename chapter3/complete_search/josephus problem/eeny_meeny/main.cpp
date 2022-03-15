#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; getline(cin, s);
	stringstream ss(s);
	int k = 0;
	while (ss >> s)
		k++;
	int n; cin >> n;
	vector<string> people(n, "");
	for (int i = 0; i < n; i++)
		cin >> people[i];
	int idx = 0;
	vector<vector<string>> teams(2, vector<string>());
	bool t = false;
	while (people.size()) {
		idx = (idx+k-1)%n--;
		teams[t].push_back(people[idx]);
		t = !t;
		people.erase(people.begin()+idx);
	}
	for (int i = 0; i < 2; i++) {
		printf("%ld\n", teams[i].size());
		for (string& s : teams[i])
			printf("%s\n", s.c_str());
	}
}
