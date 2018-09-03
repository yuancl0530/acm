/*********************************
Date: Thu Aug 23 20:14:41 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	int left,right;
}node[800*maxn];
int root[maxn],f[maxn],w[maxn],fa,ans[maxn];
int id = 0;
vector<int>v[maxn];
int modify(int left,int right,int x,int f)
{
	if (x < left || x > right) return f;
	if (!f) f = ++id;
	if (left == right) return f;
	int mid = (left+right)>>1;
	node[f].left = modify(left,mid,x,node[f].left);
	node[f].right = modify(mid+1,right,x,node[f].right);
	return f;
}
int update(int left,int right,int x,int y)
{
	if (!x || !y) return x? x:y;
	if (left == right) {ans[fa] = max(ans[fa],left); return x; }
	int mid = (left+right) >> 1;
	node[x].left = update(left,mid,node[x].left,node[y].left);
	node[x].right = update(mid+1,right,node[x].right,node[y].right);
	return x;
}
int main()
{
	int n;
	for (int i = 1;i < maxn;++i)
		for (int j = 1;i*j < maxn;++j) v[i*j].push_back(i);
	for (int i = 1;i < maxn;++i) ans[i] = -1;
	scanf("%d",&n);
	for (int i = 2;i <= n;++i) scanf("%d",&f[i]);
	for (int i = 1;i <= n;++i) scanf("%d",&w[i]);
	for (int i = 1;i <= n;++i) {
		int x = w[i];
		for (int j = 0;j < (int)v[x].size();++j) 
			root[i] = modify(1,maxn,v[x][j],root[i]);
	}
	for (int i = n;i >= 1;--i){
		fa = f[i];
		root[i] = update(1,maxn,root[fa],root[i]);
	}
	for (int i = 1;i <= n;++i) printf("%d\n",ans[i]);
	return 0;
}
