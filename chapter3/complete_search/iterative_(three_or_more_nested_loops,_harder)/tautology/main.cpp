#include <bits/stdc++.h>
using namespace std;

bool v(char c, int i) {
	return (1<<(c-'p'))&i;
}

bool eval(string& s, int i) {
	stack<bool> st;
	for (int x = s.size()-1; x >= 0; x--) {
		if (islower(s[x]))
			st.push(v(s[x], i));
		else if (s[x] == 'K') {
			bool a = st.top(); st.pop();
			bool b = st.top(); st.pop();
			st.push(a&&b);
		}
		else if (s[x] == 'A') {
			bool a = st.top(); st.pop();
			bool b = st.top(); st.pop();
			st.push(a||b);
		}
		else if (s[x] == 'N') {
			bool a = st.top(); st.pop();
			st.push(!a);
		}
		else if (s[x] == 'C') {
			bool a = st.top(); st.pop();
			bool b = st.top(); st.pop();
			st.push((!a)||b);
		}
		else if (s[x] == 'E') {
			bool a = st.top(); st.pop();
			bool b = st.top(); st.pop();
			st.push(a==b);
		}
	}
	return st.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s && s != "0") {
		bool res = true;
		for (int i = 0; i < 1<<5; i++)
			res &= eval(s, i);
		printf(res ? "tautology\n" : "not\n");
	}
}
