#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
int main() {
	int n,s,g;
	cin>>n>>s>>g;
	vector<vector<int>>d(n,vector<int>(n,1e9));
	rep(i,0,n)rep(j,0,n)cin>>d[i][j];
	rep(k,0,n)rep(i,0,n)rep(j,0,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	cout<<d[s][g];
}
