#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (getline(cin, s) && s != "") {
		stringstream ss(s);
		vector<int> ruler;
		int x;
		while (ss >> x)
			ruler.push_back(x);
		sort(ruler.begin(), ruler.end());
		int n = ruler.back();
		bool isGolomb = true;
		set<int> dists;
		for (int i = 0; i < (int)ruler.size(); i++)
			for (int j = i+1; j < (int)ruler.size(); j++)
				isGolomb &= !dists.count(ruler[j]-ruler[i]),
				dists.insert(ruler[j]-ruler[i]);
		if (!isGolomb) {
			printf("not a ruler\n");
			continue;
		}
		vector<int> missing;
		for (int i = 1; i <= n; i++)
			if (!dists.count(i))
				missing.push_back(i);
		if (missing.size()) {
			printf("missing");
			for (int y : missing)
				printf(" %d", y);
			printf("\n");
		}
		else
			printf("perfect\n");
	}
}
