#include <bits/stdc++.h>
using namespace std;
#define M 1000000007ll
#define P 1087ll
typedef long long ll;

vector<ll> h, p;

void init_hp(string& s) {
	h.assign(s.size()+1, 0);
	p.assign(s.size(), 1);
	for (int i = 1; i < (int)s.size(); i++)
		p[i] = (p[i-1]*P) % M;
	for (int i = 1; i <= (int)s.size(); i++)
		h[i] = (h[i-1]*P + s[i-1]) % M;
}

ll s_hash(int from, int to) {
	return ((h[to]-h[from]*p[to-from] % M) + M) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s, s != ".") {
		init_hp(s);
		for (int i = 1; i <= (int)s.size(); i++) {
			if ((int)s.size()%i)
				continue;
			bool valid = true;
			for (int j = 0; valid && i*(j+1) <= (int)s.size(); j++)
				valid &= s_hash(0, i) == s_hash(i*j, i*(j+1));
			if (valid) {
				printf("%d\n", (int)s.size()/i);
				break;
			}
		}
	}
}
