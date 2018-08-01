/*********************************
Date: Mon May  7 14:54:37 CST 2018
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
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	Node *left,*right;
	int sum;
	void init(Node *l=NULL,Node *r=NULL,int s=0)
	{
		left = l,right = r,sum=s;
	}
}node[maxn*20],*root[maxn];
int num[maxn],a[maxn],p[maxn],cnt,n;
Node *modify(int left,int right,int v,Node *p)
{
	if (v<left || v>right) return p;
	Node *t = &node[cnt++];
	*t = *p;
	++t->sum;
	if (left==right) return t;
	int mid = (left+right)/2;
	t->left = modify(left,mid,v,p->left);
	t->right = modify(mid+1,right,v,p->right);
	return t;
}
inline void build()
{
	cnt = 0;
	root[0] = &node[cnt++];
	root[0]->init(root[0],root[0],0);
	for (int i=1;i<=n;++i)
		root[i] = modify(1,n,num[i],root[i-1]);
}
int query(int left,int right,int k,Node *x,Node *y)
{
	if (left==right) return left;
	int mid = (left+right)/2;
	int sum = y->left->sum - x->left->sum;
	if (sum>=k) return query(left,mid,k,x->left,y->left);
	return query(mid+1,right,k-sum,x->right,y->right);
}
int main()
{
	int T,m;
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			p[i]=a[i];
		}
		sort(p+1,p+1+n);
		for (int i=1;i<=n;++i)
			num[i] = lower_bound(p+1,p+1+n,a[i])-p;
		build();
		int l,r,k,pos;
		for (int i=0;i<m;++i){
			scanf("%d%d%d",&l,&r,&k);
			pos = query(1,n,k,root[l-1],root[r]);
			printf("%d\n",p[pos]);
		}
	}
	return 0;
}
