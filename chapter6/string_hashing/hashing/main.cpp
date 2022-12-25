#include <bits/stdc++.h>
using namespace std;
#define M 1000000007ll
#define P1 131ll
#define P2 127ll
typedef long long ll;

vector<ll> h1, p1, h2, p2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	h1.assign(s.size()+1, 0);
	h2.assign(s.size()+1, 0);
	p1.assign(s.size()+1, 1);
	p2.assign(s.size()+1, 1);
	for (int i = 1; i <= (int)s.size(); i++)
		h1[i] = (h1[i-1]*P1 + s[i-1]) % M,
		p1[i] = p1[i-1]*P1 % M,
		h2[i] = (h2[i-1]*P2 + s[i-1]) % M,
		p2[i] = p2[i-1]*P2 % M;
	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		ll hash1 = ((h1[b] - h1[a]*p1[b-a])%M+M)%M;
		ll hash2 = ((h2[b] - h2[a]*p2[b-a])%M+M)%M;
		printf("%ull\n", hash1 | (hash2 << 32));
	}
}
