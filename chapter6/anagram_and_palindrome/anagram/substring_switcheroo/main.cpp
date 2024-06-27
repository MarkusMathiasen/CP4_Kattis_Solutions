#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef uint64_t ull;
typedef ull H;
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)
H hashVector(vector<ull>& s){H h{}; for(ull c:s) h=h*C+c;return h;}

ll n;
string A, B;
unordered_set<H> hashes;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> A >> B;
		for (ll len = sz(A); len > 0; len--) {
			hashes.clear();
			vector<ull> f(26, 0);
			rep(i, 0, len-1) f[B[i]-'a']++;
			rep(i, len-1, sz(B)) {
				f[B[i]-'a']++;
				hashes.insert(hashVector(f));
				f[B[i-len+1]-'a']--;
			}
			f.assign(26, 0);
			rep(i, 0, len-1) f[A[i]-'a']++;
			rep(i, len-1, sz(A)) {
				f[A[i]-'a']++;
				if (hashes.count(hashVector(f))) {
					printf("%s", A.substr(i-len+1, len).c_str());
					goto done;
				}
				f[A[i-len+1]-'a']--;
			}
		}
		printf("NONE");
done:
		printf("\n");
	}
}
