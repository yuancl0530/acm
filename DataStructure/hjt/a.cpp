/*********************************
Date: Thu Aug  2 20:11:21 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
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
	int sum;
	void init(Node *left,Node *right,int s=0)
	{
		this->left = left;
		this->right = right;
		this->sum = s;
	}
}node[maxn*20],*root[maxn];
int id;
int a[maxn],b[maxn],p[maxn];
Node *modify(int left,int right,int x,Node *p)
{
	if (x < left || x > right) return p;
	Node *t = &node[id++];
	*t = *p;
	++t->sum;
	if (left == right) return t;
	int mid = (left+right)>>1;
	t->left = modify(left,mid,x,p->left);
	t->right = modify(mid+1,right,x,p->right);
	return t;
}
void build(int n,int *num)
{
	root[0] = &node[id++];
	root[0]->init(root[0],root[0]);
	for (int i = 1;i <= n;++i)
		root[i] = modify(1,n,num[i],root[i-1]);
}
int query(int left,int right,int k,Node *x,Node *y)
{
	if (left == right) return left;
	int mid = (left+right)>>1;
	int sum = y->left->sum - x->left->sum;
	//cout<<left<<" "<<mid<<" "<<sum<<endl;
	if (k <= sum) return query(left,mid,k,x->left,y->left);
	return query(mid+1,right,k-sum,x->right,y->right);
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		id = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			p[i] = a[i];
		}
		sort(p+1,p+1+n);
		//int cnt = unique(p+1,p+1+n)-p-1;
		for (int i = 1;i <= n;++i)
			b[i] = lower_bound(p+1,p+1+n,a[i])-p;
		build(n,b);
	/*	for (int i = 1;i <= n;++i)
			cout<<b[i]<<" ";
		cout<<endl;*/
		int l,r,k;
		while (m--){
			scanf("%d%d%d",&l,&r,&k);
			int t = query(1,n,k,root[l-1],root[r]);
			printf("%d\n",p[t]);
		}
	}
	return 0;
}
