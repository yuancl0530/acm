/*********************************
Date: Fri May  4 20:59:19 CST 2018
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
	int sum;
	Node *left;
	Node *right;
	void init(int v=0,Node *l=NULL,Node *r=NULL)
	{
		sum = v;
		left = l;
		right = r;
	}
	void copy(Node *t)
	{
		left = t->left;
		right = t->right;
		sum = t->sum;
	}
}node[maxn*20],*root[maxn];
int cnt,n;
int a[maxn],p[maxn],num[maxn];
Node *modify(int left,int right,int v,Node *t)
{
	if (v<left || v>right) return t;
	int mid = (left+right)/2;
	Node *p = &node[cnt++];
	p->copy(t);
	++p->sum;
	if (left == right) return p;
	p->left = modify(left,mid,v,t->left);
	p->right = modify(mid+1,right,v,t->right);
	return p;
}
void build()
{
	cnt = 0;
	root[0] = &node[cnt++];
	root[0]->init(0,root[0],root[0]);
	for (int i=1;i<=n;++i){
		root[i] = modify(1,n,num[i],root[i-1]);
	}
}
int query(int left,int right,int k,Node *x,Node* y)
{
	if (left==right) return left;
	int mid = (left+right)/2;
	int sum = y->left->sum - x->left->sum;
	if (sum >= k){
		return query(left,mid,k,x->left,y->left);
	}
	else {
		return query(mid+1,right,k-sum,x->right,y->right);
	}
}
int main()
{
	int T,m;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			p[i] = a[i];
		}
		sort(p+1,p+1+n);
		for (int i=1;i<=n;++i)
			num[i] = lower_bound(p+1,p+1+n,a[i])-p;
		build();
		int l,r,k;
		for (int i=0;i<m;++i){
			scanf("%d%d%d",&l,&r,&k);
			int pos = query(1,n,k,root[l-1],root[r]);
			printf("%d\n",p[pos]);
		}
	}
	return 0;
}
