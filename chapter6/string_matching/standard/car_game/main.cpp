#include <bits/stdc++.h>
using namespace std;

bool one[26], two[26][26];
int three[26][26][26];
vector<string> A;

int main() {
	int n, m; cin >> n >> m;
	A.assign(n, "");
	memset(three, -1, sizeof(three));
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		memset(one, 0, sizeof(one));
		memset(two, 0, sizeof(two));
		for (char c : A[i]) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++)
					if (two[j][k] && three[j][k][c-'a'] == -1)
						three[j][k][c-'a'] = i;
				two[j][c-'a'] = one[j];
			}
			one[c-'a'] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int x = three[s[0]-'A'][s[1]-'A'][s[2]-'A'];
		if (x == -1)
			printf("No valid word\n");
		else
			printf("%s\n", A[x].c_str());
	}
}
