/*********************************
Date: Thu Aug  9 20:14:38 CST 2018
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
	Node *left,*right;
	ll sum,lazy;
}node[50*maxn],*root[maxn];
int id;
int a[maxn],tid[maxn];
Node *build(int left,int right)
{
	Node *t = &node[id++];
	t->sum = t->lazy = 0;
	if (left == right){
		t->sum = a[left];
		return t;
	}
	int mid = (left+right)>>1;
	t->left = build(left,mid);
	t->right = build(mid+1,right);
	t->sum = t->left->sum + t->right->sum;
	return t;
}
inline ll sum(int l,int r,Node *p)
{
	return p->sum + (r-l+1)*p->lazy;
}
void push(int left,int right,Node *p)
{
	if (p->lazy == 0) return ;
	Node *l = p->left;
	Node *r = p->right;
	p->left = &node[id++];
	p->right = &node[id++];
	*p->left = *l;
	*p->right = *r;
	p->left->lazy += p->lazy;
	p->right->lazy += p->lazy;
	p->sum += p->lazy * (right-left+1);
	p->lazy = 0;
	return ;
}
Node *update(int left,int right,int l,int r,int v,Node *p)
{
	if (r < left || l > right) return p;
	Node *t = &node[id++];
	*t = *p;
	if (l <= left && right <= r){
		t->lazy += v;
		return t;
	}
	push(left,right,t);
	int mid = (left+right) >> 1;
	t->left = update(left,mid,l,r,v,t->left);
	t->right = update(mid+1,right,l,r,v,t->right);

	t->sum = sum(left,mid,t->left) + sum(mid+1,right,t->right);
	return t;
}
ll query(int left,int right,int l,int r,Node *p,ll lazy=0)
{
	if (r < left || l > right) return 0;
	lazy += p->lazy;
	if (l <= left && right <= r) 
		return p->sum + (right-left+1)*lazy;
	int mid = (left+right)>>1;
	ll sl = query(left,mid,l,r,p->left,lazy);
	ll sr = query(mid+1,right,l,r,p->right,lazy);
	return sl + sr;
}
int main()
{
	int n,m,l,r,v;
	char op[3];
	while (scanf("%d%d",&n,&m) != EOF){
		id = 0;
		for (int i = 1;i <= n;++i)
			scanf("%d",&a[i]);
		root[0] = build(1,n);
		int ti = 0;
		tid[ti] = id;
		for (int i = 0;i < m;++i){
			scanf("%s",op);
			if (op[0] == 'C'){
				++ti;
				root[ti] = root[ti-1];
				scanf("%d%d%d",&l,&r,&v);
				root[ti] = update(1,n,l,r,v,root[ti]);
				tid[ti] = id;
			}
			else if (op[0] == 'Q'){
				scanf("%d%d",&l,&r);
				ll ans = query(1,n,l,r,root[ti]);
				printf("%lld\n",ans);
			}
			else if (op[0] == 'H'){
				scanf("%d%d%d",&l,&r,&v);
				ll ans = query(1,n,l,r,root[v]);
				printf("%lld\n",ans);
			}
			else{
				scanf("%d",&v);
				ti = v;
				id = tid[v];
			}
		}
	}
	return 0;
}
