/*********************************
Date: Sat Aug 11 16:04:27 CST 2018
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
	int sum;
}node[20*maxn], *root[maxn];
int n,id;
int last[maxn],a[maxn];
Node *modify(int left,int right,int x,int v,Node *p)
{
	if (x < left || x > right) return p;
	Node *t = &node[id++];
	*t = *p;
	t->sum += v;
	if (left == right) return t;
	int mid = (left+right)>>1;
	t->left = modify(left,mid,x,v,p->left);
	t->right = modify(mid+1,right,x,v,p->right);
	return t;
}
int sum(int left,int right,int l,int r,Node *p)
{
	if (l > right || r < left) return 0;
	if (l <= left && right <= r) return p->sum;
	int mid = (left+right)>>1;
	int x = sum(left,mid,l,r,p->left);
	int y = sum(mid+1,right,l,r,p->right);
	return x + y;
}
int query(int left,int right,int k,Node *x,Node *y)
{
	if (left == right) return left;
	int sum = x->left->sum - y->left->sum;
	int mid = (left+right)>>1;
	if (sum >= k) return query(left,mid,k,x->left,y->right);
	return query(mid+1,right,k-sum,x->right,y->right);
}
int main()
{
	int T,m;
	int kase = 0;
	scanf("%d",&T);
	while (T--){
		printf("Case %d:",++kase);
		id = 0;
		CL(last);
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++i)
			scanf("%d",&a[i]);
		root[n+1] = &node[id++];
		root[n+1]->left = root[n+1]->right = root[n+1];
		for (int i = n;i >= 1;--i){
			root[i] = root[i+1];
			if (last[a[i]]){
				root[i] = modify(1,n,last[a[i]],-1,root[i]);
			}
			last[a[i]] = i;
			root[i] = modify(1,n,i,1,root[i]);
		}
		int ans = 0;
		int l,r,x,y;
		while (m--){
			scanf("%d%d",&x,&y);
			l = (x+ans)%n+1;
			r = (y+ans)%n+1;
			if (l > r) swap(l,r);
			int s = sum(1,n,l,r,root[l]);
			ans = query(1,n,(s+1)>>1,root[l],root[r+1]);
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}
