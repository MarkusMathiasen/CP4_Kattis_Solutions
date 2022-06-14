#include <bits/stdc++.h>
using namespace std;

struct node {
	node *l, *r;
	int v;
	node(int v) : l(nullptr), r(nullptr), v(v) {}
};

int n, k;
vector<node*> trees;

bool eq(node* a, node* b) {
	if (a == nullptr)
		return b == nullptr;
	if (b == nullptr)
		return false;
	return eq(a->l, b->l) && eq(a->r, b->r);
}
void insert(node* t, node* v) {
	if (v->v > t->v)
		if (t->r == nullptr)
			t->r = v;
		else
			insert(t->r, v);
	else
		if (t->l == nullptr)
			t->l = v;
		else
			insert(t->l, v);
}

int main() {
	scanf("%d%d", &n, &k);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int v; scanf("%d", &v);
		trees.push_back(new node(v));
		for (int j = 1; j < k; j++) {
			scanf("%d", &v);
			insert(trees[i], new node(v));
		}
		bool similar = false;
		for (int k = 0; k < i; k++)
			similar |= eq(trees[k], trees[i]);
		res += !similar;
	}
	printf("%d\n", res);
}
