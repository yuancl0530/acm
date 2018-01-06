/*********************************
Date: Sat Sep 23 12:05:57 CST 2017
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
const int maxn = 1e6 + 100;
struct Node
{
	int left;
	int right;
	LL mi,ma;
}node[maxn];
LL a[maxn];
void  build(int left,int right,int pos=1)
{
	node[pos].left=left;
	node[pos].right=right;
	if (left==right){
		node[pos].mi=node[pos].ma=a[left];
		return;
	}
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
	node[pos].ma=max(node[2*pos].ma,node[2*pos+1].ma);
	node[pos].mi=min(node[2*pos].mi,node[2*pos+1].mi);
}
void update(LL value,int i,int pos=1)
{
	if (i<node[pos].left || i>node[pos].right)
		return ;
	if (node[pos].left==node[pos].right){
		node[pos].ma=node[pos].mi=a[node[pos].left]=value;
		return;	
	}
	update(value,i,2*pos);
	update(value,i,2*pos+1);
	node[pos].ma=max(node[2*pos].ma,node[2*pos+1].ma);
	node[pos].mi=min(node[2*pos].mi,node[2*pos+1].mi);
}
LL queryma(int left,int right,int pos=1)
{
	if (left >node[pos].right || right <node[pos].left)
		return -INF;
	if (left<=node[pos].left&& node[pos].right<=right)
		return node[pos].ma;
	LL l=queryma(left,right,2*pos);
	LL r=queryma(left,right,2*pos+1);
	return max(l,r);
}
LL querymi(int left,int right,int pos=1)
{
	if (left >node[pos].right || right <node[pos].left)
		return INF;
	if (node[pos].left>=left && node[pos].right <=right)
		return node[pos].mi;
	LL l=querymi(left,right,2*pos);
	LL r=querymi(left,right,2*pos+1);
	return min(l,r);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int k;
		scanf("%d",&k);
		int n=1<<k;
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		build(0,n-1);
		LL op,x,y;
		int m;
		scanf("%d",&m);
		while (m--){
			scanf("%lld%lld%lld",&op,&x,&y);
			if (op==1){
				LL mi=querymi(x+1,y+1);
				LL ma=queryma(x+1,y+1);
				LL ans;
				if (mi<0){
					if (ma>=0)
						ans=mi*ma;
					else
						ans=ma*ma;
				}
				else
					ans=mi*mi;
				printf("%lld\n",ans);
			}
			else
				update(y,x+1);
		}

	}
	return 0;
}
