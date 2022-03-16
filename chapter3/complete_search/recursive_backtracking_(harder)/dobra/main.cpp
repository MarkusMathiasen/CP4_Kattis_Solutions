#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
vector<int> indexes;

bool vowel(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool valid() {
	for (int i = 1; i < (int)s.size()-1; i++) {
		if (vowel(s[i-1]) && vowel(s[i]) && vowel(s[i+1]))
			return false;
		if (!vowel(s[i-1]) && !vowel(s[i]) && !vowel(s[i+1]))
			return false;
	}
	bool hasL = false;
	for (char c : s)
		hasL |= c == 'L';
	return hasL;
}

ll rec(int idx) {
	if (idx == (int)indexes.size())
		return valid();
	ll res = 0;
	s[indexes[idx]] = 'A'; res += 5*rec(idx+1);
	s[indexes[idx]] = 'B'; res += 20*rec(idx+1);
	s[indexes[idx]] = 'L'; res += rec(idx+1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == '_')
			indexes.push_back(i);
	printf("%lld\n", rec(0));
}
