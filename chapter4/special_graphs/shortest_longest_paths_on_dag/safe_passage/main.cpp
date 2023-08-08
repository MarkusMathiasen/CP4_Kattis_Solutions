#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi A, order, dist;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, -1);
	rep(i, 0, n) cin >> A[i];
	rep(i, 0, 1<<n) order.push_back(i);
	sort(all(order), [](const int a, const int b) {
		return __builtin_popcount(a) < __builtin_popcount(b);
	});
	dist.assign(1<<n, 1e9);
	dist[0] = 0;
	for (int i : order) {
		rep(a, 0, n) { if ((1<<a)&i) continue;
			rep(b, a+1, n) { if ((1<<b)&i) continue;
				int state = i | (1<<a) | (1<<b);
				if (state == (1<<n)-1)
					dist[state] = min(dist[state], dist[i]+max(A[a],A[b]));
				rep(c, 0, n) { if (!((1<<c)&state)) continue;
					int nstate = state^(1<<c);
					dist[nstate] = min(dist[nstate], dist[i]+max(A[a], A[b])+A[c]);
				}
			}
		}
	}
	printf("%d\n", dist[(1<<n)-1]);
}
