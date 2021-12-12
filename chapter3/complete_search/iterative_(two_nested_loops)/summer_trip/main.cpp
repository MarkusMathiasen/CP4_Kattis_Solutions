#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int res = 0;
	vector<int> nxt(26, 0);
	for (int i = 0; i < 26; i++)
		nxt[i] = s.find('a'+i);
	for (int i = 0; i < (int)s.size(); i++) {
		nxt[s[i]-'a'] = s.find(s[i], i+1);
		for (int j = 0; j < 26; j++)
			res += nxt[j] != -1 && (nxt[j] < nxt[s[i]-'a'] || nxt[s[i]-'a'] == -1);
	}
	printf("%d\n", res);
}
