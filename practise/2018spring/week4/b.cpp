/*********************************
Date: Thu Mar 29 12:51:12 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
#define N 100000
int pos[maxn];
vector<int>to[maxn];
LL dp[maxn];
int n;
struct Plank
{
	int h,x,y,v;
	friend bool operator < (Plank a,Plank b){
		return a.h<b.h;
	}
}p[maxn];
struct Node
{
	int left,right,lazy;
	Node()
	{
		left=right=right=lazy=0;
	}
}node[4*maxn];
void build(int left,int right, int pos=1)
{
	node[pos].left=left;
	node[pos].right=right;
	node[pos].lazy=0;
	if (left==right) {
		return ;
	}
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
	return ;
}
void push(int pos)
{
	if (!node[pos].lazy) return ;
	int l=2*pos;
	int r= l+1;
	node[l].lazy=node[pos].lazy;
	node[r].lazy=node[pos].lazy;
	node[pos].lazy=0;
}
void update(int left,int right,int v,int pos=1)
{
	if (left>node[pos].right || right <node[pos].left){
		return ;
	}
	if (left<=node[pos].left && node[pos].right<=right){
		node[pos].lazy=v;
		return ;
	}
	push(pos);
	update(left,right,v,2*pos);
	update(left,right,v,2*pos+1);
	return ;
}
int query(int v,int pos=1)
{
	if (v>node[pos].right || v <node[pos].left){
		return 0;
	}
	if (node[pos].left<=v && v<=node[pos].right && node[pos].lazy){
		return node[pos].lazy;
	}
	push(pos);
	int l = query(v,2*pos);
	int r = query(v,2*pos+1);
	return max(l,r);
}
LL solve()
{
	CL(dp);
	dp[n]=100+p[n].v;
	for (int i=n;i>0;--i){
		if (dp[i]<=0) continue;
		for (int j=0;j<to[i].size();++j){
			int u=to[i][j];
			dp[u]=max(dp[u],dp[i]+p[u].v);
		}
	}
	return dp[0]>0? dp[0]:-1;
}
int main()
{
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;++i){
			scanf("%d%d%d%d",&p[i].h,&p[i].x,&p[i].y,&p[i].v);
			to[i].clear();
		}
		sort(p+1,p+1+n);
		for (int i=1;i<=n;++i){
			pos[p[i].h]=i;
		}
		build(1,N);
		for (int i=1;i<=n;++i){
			int t=query(p[i].x);
			to[i].push_back(t);
			t=query(p[i].y);
			if (t || to[i][0]) to[i].push_back(t);
			update(p[i].x,p[i].y,pos[p[i].h]);
		}
		printf("%lld\n",solve());
	}
	return 0;
}
