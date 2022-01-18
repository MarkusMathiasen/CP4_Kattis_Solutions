#include <bits/stdc++.h>
using namespace std;

struct country {
	int gold;
	int silver;
	int bronze;
	string name;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		vector<country> countries(n, country());
		for (int i = 0; i < n; i++)
			cin >> countries[i].name >> countries[i].gold >> countries[i].silver >> countries[i].bronze;
		bool wins = false;
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze+a.silver != b.bronze + b.silver)
				return a.bronze+a.silver > b.bronze+b.silver;
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.gold != b.gold)
				return a.gold > b.gold;
			if (a.bronze+a.silver != b.bronze + b.silver)
				return a.bronze+a.silver > b.bronze+b.silver;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze+a.gold != b.bronze + b.gold)
				return a.bronze+a.gold > b.bronze+b.gold;
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.silver != b.silver)
				return a.silver > b.silver;
			if (a.bronze+a.gold != b.bronze + b.gold)
				return a.bronze+a.gold > b.bronze+b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.silver+a.gold != b.silver + b.gold)
				return a.silver+a.gold > b.silver+b.gold;
			if (a.bronze != b.bronze)
				return a.bronze > b.bronze;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze != b.bronze)
				return a.silver > b.silver;
			if (a.silver+a.gold != b.silver + b.gold)
				return a.silver+a.gold > b.silver+b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		sort(countries.begin(), countries.end(), [](const country& a, const country& b) {
			if (a.bronze+a.silver+a.gold != b.bronze+b.silver + b.gold)
				return a.bronze+a.silver+a.gold > b.bronze+b.silver+b.gold;
			if (a.name == "Canada")
				return true;
			if (b.name == "Canada")
				return false;
			return a.name < b.name;
		});
		wins |= countries[0].name == "Canada";
		if (wins)
			printf("Canada wins!\n");
		else
			printf("Canada cannot win.\n");
	}	
}
