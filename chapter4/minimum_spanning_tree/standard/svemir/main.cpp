#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct planet {
	int i, x, y, z;
};

int N;
vector<planet> A;
vector<tuple<int, int, int>> edges;
vi uf;

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	scanf("%d", &N);
	A.assign(N, planet());
	rep(i, 0, N) A[i].i = i;
	rep(i, 0, N) scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].z);
	sort(all(A), [](const planet& a, const planet& b) {
		return a.x < b.x;
	});
	rep(i, 0, N-1)
		edges.push_back({abs(A[i].x-A[i+1].x), A[i].i, A[i+1].i});
	sort(all(A), [](const planet& a, const planet& b) {
		return a.y < b.y;
	});
	rep(i, 0, N-1)
		edges.push_back({abs(A[i].y-A[i+1].y), A[i].i, A[i+1].i});
	sort(all(A), [](const planet& a, const planet& b) {
		return a.z < b.z;
	});
	rep(i, 0, N-1)
		edges.push_back({abs(A[i].z-A[i+1].z), A[i].i, A[i+1].i});
	sort(all(edges));
	uf.assign(N, 0);
	rep(i, 1, N) uf[i] = i;
	int res = 0;
	for (auto [w,a,b] : edges) {
		if (issame(a, b)) continue;
		same(a, b);
		res += w;
	}
	printf("%d\n", res);
}
