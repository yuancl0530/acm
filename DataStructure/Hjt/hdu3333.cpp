/*********************************
Date: Tue Aug 21 15:36:32 CST 2018
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
const int maxn = 1e6 + 100;
struct Node
{
	Node *left,*right;
	ll sum;
}node[6*maxn],*root[maxn];
int a[maxn],b[maxn],last[maxn],n,id;
Node *modify(int left,int right,int x,ll v,Node *p)
{
	if (x < left || x > right) return p;
	Node *t = &node[id++];
	*t = *p;
	t->sum += v;
	if (left == right) return t;
	int mid = (left+right) >> 1;
	t->left = modify(left,mid,x,v,p->left);
	t->right = modify(mid+1,right,x,v,p->right);
	return t;
}
void build()
{
	root[n+1] = &node[id++];
	root[n+1]->left = root[n+1]->right = root[n+1];
	for (int i = n;i >= 1;--i){
		root[i] = root[i+1];
		if (last[a[i]]) root[i] = modify(1,n,last[a[i]],-b[a[i]],root[i]);
		last[a[i]] = i;
		root[i] = modify(1,n,i,b[a[i]],root[i]);
	}
}
ll query(int left,int right,int x,Node *p)
{
	if (right <= x) return p->sum;
	if (x < left) return 0;
	int mid = (left+right) >> 1;
	return query(left,mid,x,p->left) + query(mid+1,right,x,p->right);
}
int main()
{
	int T,m,l,r;
	scanf("%d",&T);
	while (T--){
		id = 0;
		scanf("%d",&n);
		int cnt = 1;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[cnt++] = a[i];
			last[i] = 0;
		}
		sort(b+1,b+cnt);
		cnt = unique(b+1,b+cnt) - b;
		for (int i = 1;i <= n;++i) a[i] = lower_bound(b+1,b+cnt,a[i]) - b;
		build();
		scanf("%d",&m);
		while (m--){
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,n,r,root[l]));
		}
	}
	return 0;
}
