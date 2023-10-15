#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	string s1, s2; getline(cin, s1);
	while (T--) {
		// Read lines
		getline(cin, s1); getline(cin, s2);
		vector<string> l1, l2;
		stringstream ss(s1);
		while (ss >> s1) l1.push_back(s1);
		stringstream ss2(s2);
		while (ss2 >> s2) l2.push_back(s2);
		if (sz(l1) != sz(l2)) {
			printf("-\n");
			continue;
		}

		// Declare data structures
		map<string, vector<string>> p1, p2;
		queue<string> q1, q2, Q1, Q2;
		map<string, string> m1, m2;

		// Construct queues
		bool possible = true;
		rep(i, 0, sz(l1)) {
			if (l1[i][0] != '<' && l2[i][0] != '<')
				possible &= l1[i] == l2[i];
			else if (l1[i][0] == '<' && l2[i][0] == '<') {
				p1[l1[i]].push_back(l2[i]);
				p2[l2[i]].push_back(l1[i]);
				Q1.push(l1[i]);
				Q2.push(l2[i]);
			}
			else if (l1[i][0] == '<') {
				possible &= !m1.count(l1[i]) || m1[l1[i]] == l2[i];
				if (!m1.count(l1[i])) q1.push(l1[i]);
				m1[l1[i]] = l2[i];
			}
			else if (l2[i][0] == '<') {
				possible &= !m2.count(l2[i]) || m2[l2[i]] == l1[i];
				if (!m2.count(l2[i])) q2.push(l2[i]);
				m2[l2[i]] = l1[i];
			}
		}
		loop:
		while (!q1.empty()) {
			for (string s : p1[q1.front()]) {
				if (!m2.count(s)) q2.push(s);
				possible &= !m2.count(s) || m2[s] == m1[q1.front()];
				m2[s] = m1[q1.front()];
			}
			q1.pop();
		}
		while (!q2.empty()) {
			for (string s : p2[q2.front()]) {
				if (!m1.count(s)) q1.push(s);
				possible &= !m1.count(s) || m1[s] == m2[q2.front()];
				m1[s] = m2[q2.front()];
			}
			q2.pop();
		}
		if (!q1.empty()) goto loop;

		while (!Q1.empty()) {
			if (!m1.count(Q1.front())) m1[Q1.front()] = "a";
			Q1.pop();
		}
		while (!Q2.empty()) {
			if (!m2.count(Q2.front())) m2[Q2.front()] = "a";
			Q2.pop();
		}

		// Print result
		if (!possible)
			printf("-\n");
		else {
			for (string s : l1)
				printf("%s ", s[0] == '<' ? m1[s].c_str() : s.c_str());
			printf("\n");
		}
	}
}
