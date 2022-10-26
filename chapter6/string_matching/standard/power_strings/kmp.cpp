#include <bits/stdc++.h>
using namespace std;

vector<int> b;

void kmp_pre(string& sub) {
	b.assign(sub.size()+1, -1);
	int j = -1, i = 0;
	while (i < (int)b.size()) {
		while (j >= 0 && sub[j] != sub[i])
			j = b[j];
		j++, i++;
		b[i] = j;
	}
}

int kmp_find(string& s, string& sub) {
	int i = 0, j = -1;
	while (i < (int)s.size()) {
		while (j >= 0 && s[i] != sub[j])
			j = b[j];
		j++, i++;
		if (j == (int)sub.size())
			return i-j;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s && s != ".") {
		kmp_pre(s);
		string s2 = s+s;
		int l = kmp_find(s2, s);
		assert(l != -1);
		printf("%ld\n", s.size()/l);
	}
}
