/*********************************
Date: Sat Nov 18 14:12:34 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
inline int Max(int a,int b)
{
	return a>b? a:b;
}
inline int Min(int a,int b)
{
	return a<b? a:b;
}
struct Node
{
	int left;
	int right;
	int mi,ma;
}node[4*maxn];
int n,a[maxn],b[maxn];
void build(int left,int right ,int pos=1)
{
	node[pos].left=left;
	node[pos].right=right;
	if (left==right){
		node[pos].ma=a[left];
		node[pos].mi=b[left];
		return;
	}
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
	node[pos].mi=Min(node[2*pos].mi,node[2*pos+1].mi);
	node[pos].ma=Max(node[2*pos].ma,node[2*pos+1].ma);
}
int f_max(int left,int right,int pos=1)
{
	if (node[pos].right < left || node[pos].left > right)
		return -INF;
	if (left <= node[pos].left && node[pos].right <= right)
		return node[pos].ma;
	int l=f_max(left,right,2*pos);
	int r=f_max(left,right,2*pos+1);
	return Max(l,r);
}
int f_min(int left,int right,int pos=1)
{
	if (node[pos].left > right || node[pos].right <left)
		return INF;
	if (left <= node[pos].left && node[pos].right<= right)
		return node[pos].mi;
	int l=f_min(left,right,2*pos);
	int r=f_min(left,right,2*pos+1);
	return Min(l,r);
}
int b_ma(int s)
{
	int l=s;
	int r=n+1;
	int mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (f_min(s,mid) >= f_max(s,mid))
			l=mid;
		else
			r=mid;
	}
	if (f_min(s,l) == f_max(s,l))
		return l;
	return 0;
}
int b_mi(int s)
{
	int l=s-1;
	int r=n;
	int mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (f_min(s,mid) <= f_max(s,mid))
			r=mid;
		else
			l=mid;
	}
	if (f_min(s,r) == f_max(s,r))
		return r;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	build(1,n);
	LL ans=0;
	for (int i=1;i<=n;++i){
		int l=b_mi(i);
		int r=b_ma(i);
		if (l && r)
			ans+=r-l+1;
	}
	printf("%lld\n",ans);
	return 0;
}
