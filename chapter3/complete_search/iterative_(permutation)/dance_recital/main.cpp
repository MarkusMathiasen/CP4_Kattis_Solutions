#include <bits/stdc++.h>
using namespace std;

int countQuicks(string& a, string& b) {
	int res = 0;
	int ai = 0, bi = 0;
	while (ai < (int)a.size() && bi < (int)b.size())
		if (a[ai] == b[bi])
			ai++, bi++, res++;
		else if (a[ai] < b[bi])
			ai++;
		else
			bi++;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int R; cin >> R;
	vector<string> dances(R, "");
	for (int i = 0; i < R; i++)
		cin >> dances[i];
	int res = 1e9;
	sort(dances.begin(), dances.end());
	do {
		int att = 0;
		for (int i = 0; i < R-1; i++)
			att += countQuicks(dances[i], dances[i+1]);
		res = min(res, att);
	} while (next_permutation(dances.begin(), dances.end()));
	printf("%d\n", res);
}
