/*********************************
Date: Mon Mar  5 20:50:13 CST 2018
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
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 500 + 100;
struct Node
{
	int left;
	int right;
	int v;
	Node()
	{
		left=right=v=0;
	}
}node[maxn][4*maxn];
int Graph[maxn][maxn];
int Graph2[maxn][maxn];
void init()
{
	for (int i=0;i<maxn;++i){
		for (int j=0;j<maxn;++j)
			Graph[i][j] = 1e9+7;
	}
}
int  build(int d,int left,int right,int pos =1)
{
	node[d][pos].left = left;
	node[d][pos].right = right;
	if (left > right)
	if (left == right){
		node[d][left].v = Graph[d][left];
	}
	int l = build(left,(left+right)/2,2*pos);
	int r = build((left+right)/2+1,right,2*pos+1);
	node[d][pos].v = max(l,r);
}
int query(int d,int l,int r,int pos =1)
{
	if (r<node[d][pos].left || node[d][pos].right <l)
		return -1;
	if (l<=node[d][pos].left && node[d][pos].right <=r)
		return node[d][pos].v;
	int ll = query(d,l,r,2*pos);
	int rr = query(d,l,r,2*pos+1);
	return max(ll,rr);
}
int main()
{
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	int x,y,t;
	init();
	for (int i=0;i<q;++i){
		scanf("%d%d%d",&x,&y,&t);
		Graph[x][y] = t;
	}
	for (int i=1;i<=n;++i)
		build(i,1,m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			Graph2[i][j] = query(i,j,j+k-1);
			if (Graph2[i][j] == -1)
				Graph2[i][j] = 1e9+7;
		}
	}
	cout<<"***"<<endl;
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j){
			Graph[i][j] = Graph2[j][i];
		}
	}
	CL(node);
	int ans = INF;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			int t = query(i,j,j+k-1);
			if (t!=-1)
				ans = min(ans,t);
		}
	}
	for (int i=1;i<=m;++i)
		build(i,1,n);
	if (ans > 1e9)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}
