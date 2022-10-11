#include <bits/stdc++.h>
using namespace std;

vector<int> b;

void kmp_pre(string sub) {
	b.assign(sub.size()+1, -1);
	int i = 0, j = -1;
	while (i < (int)b.size()) {
		while (j >= 0 && sub[j] != sub[i])
			j = b[j];
		j++, i++;
		b[i] = j;
	}
}

bool kmp_search(string& s, string sub) {
	int i = 0, j = 0;
	while (i < (int)s.size()) {
		while (j >= 0 && s[i] != sub[j])
			j = b[j];
		j++, i++;
		if (j == (int)sub.size())
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	kmp_pre("CD");
	int res = 0;
	while (n--) {
		string s; cin >> s;
		res += !kmp_search(s, "CD");
	}
	printf("%d\n", res);

}
