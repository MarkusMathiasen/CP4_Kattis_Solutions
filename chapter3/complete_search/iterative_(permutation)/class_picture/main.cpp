#include <bits/stdc++.h>
using namespace std;

vector<string> names;
unordered_map<string, int> name_to_num;
unordered_map<int, string> num_to_name;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n) {
		name_to_num.clear();
		num_to_name.clear();
		names.assign(n, "");
		for (int i = 0; i < n; i++)
			cin >> names[i];
		sort(names.begin(), names.end());
		for (int i = 0; i < n; i++)
			name_to_num[names[i]] = i,
			num_to_name[i] = names[i];
		bool conflict[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				conflict[i][j] = 0;
		int p; cin >> p;
		while (p--) {
			string a, b; cin >> a >> b;
			int ia = name_to_num[a];
			int ib = name_to_num[b];
			conflict[ia][ib] = 1;
			conflict[ib][ia] = 1;
		}
		vector<int> nums(n, 0);
		for (int i = 0; i < n; i++)
			nums[i] = i;
		bool found = false;
		int lastProblem = 0;
		do {
			if (conflict[nums[lastProblem]][nums[lastProblem+1]])
				continue;
			bool valid = true;
			for (int i = 0; i < n-1 && valid; i++)
				if (conflict[nums[i]][nums[i+1]])
					valid = false,
					lastProblem = i;
			if (!valid)
				continue;
			found = true;
			break;
		} while (next_permutation(nums.begin(), nums.end()));
		if (found) {
			for (int x : nums)
				printf("%s ", num_to_name[x].c_str());
			printf("\n");
		}
		else
			printf("You all need therapy.\n");
	}
}
