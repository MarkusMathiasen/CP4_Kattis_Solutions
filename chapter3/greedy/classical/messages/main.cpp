#include <bits/stdc++.h>
using namespace std;

vector<string> words;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s, s != "#")
		words.push_back(s);
	sort(words.begin(), words.end(), [](const string& a, const string& b) {
		return a.size() < b.size();
	});
	string mes = "";
	while (cin >> s, s != "#") {
		mes += s;
		if (mes.back() != '|')
			continue;
		mes.pop_back();
		int res = 0, maxi = mes.size();
		for (int i = mes.size()-1; i >= 0; i--)
			for (string& w : words)
				if (i + (int)w.size() <= maxi && w == mes.substr(i, w.size()))
					maxi = i,
					res++;
		printf("%d\n", res);
		mes = "";
	}
}
