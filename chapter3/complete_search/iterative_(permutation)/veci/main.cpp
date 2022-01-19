#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	string s2 = s;
	next_permutation(s.begin(), s.end());
	if (s <= s2)
		cout << 0 << endl;
	else
		cout << s << endl;
}
