#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string num;
int i;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> num >> i) {
		reverse(all(num));
		int pos = 0;
		while (i) {
			int mod = isdigit(num[pos]) ? 10 : 26;
			int am = i%mod;
			i /= mod;
			while (am--) {
				if (num[pos] == '9') num[pos]='0', i++;
				else if (num[pos] == 'z') num[pos] = 'a', i++;
				else if (num[pos] == 'Z') num[pos] = 'A', i++;
				else num[pos]++;
			}
			if (i && pos == sz(num)-1) {
				i--;
				if (isdigit(num[pos])) num.push_back('1');
				else if (islower(num[pos])) num.push_back('a');
				else if (isupper(num[pos])) num.push_back('A');
				else assert(false);
			}
			pos++;
		}
		reverse(all(num));
		printf("%s\n", num.c_str());
	}
}
