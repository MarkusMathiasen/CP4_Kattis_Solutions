#include <bits/stdc++.h>
using namespace std;

vector<int> b;
vector<int> res;

void kmp_pre(string& sub) {
	b.assign(sub.size()+1, -1);
	int j = -1, i = 0;
	while (i < (int)sub.size()) {
		while (j >= 0 && sub[j] != sub[i])
			j = b[j];
		j++, i++;
		b[i] = j;
	}
}

void kmp_find(string& s, string& sub) {
	res.assign(0, 0);
	int i = 0, j = 0;
	while (i < (int)s.size()) {
		while (j >= 0 && s[i] != sub[j])
			j = b[j];
		j++, i++;
		if (j == (int)sub.size())
			res.push_back(i-j),
			j = b[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string sub, s;
	while (getline(cin, sub), getline(cin, s)) {
		kmp_pre(sub);
		kmp_find(s, sub);
		for (int x : res)
			printf("%d ", x);
		printf("\n");
	}
}
