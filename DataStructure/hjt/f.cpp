/*********************************
Date: Wed Aug  8 19:19:43 CST 2018
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
struct {int l,r,h;}q[maxn];
int a[maxn],b[2*maxn],cnt;
struct Node
{
	Node *left,*right;
	int sum;
	void init(Node *l=NULL,Node *r=NULL,int s=0)
	{
		left = l;
		right = r;
		sum = s;
	}
}node[20*maxn],*root[maxn];
int id;
Node *modify(int left,int right,int x,Node *p)
{
	if (x < left || x > right ) return p;
	Node *t = &node[id++];
	*t = *p;
	++t->sum;
	if (left == right) return t;
	int mid = (left+right)>>1;
	t->left = modify(left,mid,x,p->left);
	t->right = modify(mid+1,right,x,p->right);
	return t;
}
void build(int n)
{
	root[0] = &node[id++];
	root[0]->init(root[0],root[0]);
	for (int i = 1;i <= n;++i)
		root[i] = modify(1,cnt,a[i],root[i-1]);
}
int query(int left,int right,int v,Node *x,Node *y)
{
	if (left > v) return 0;
	if (v>=right) return y->sum - x->sum;
	int mid = (left+right)>>1;
	int l = query(left,mid,v,x->left,y->left);
	int r = query(mid+1,right,v,x->right,y->right);
	return l + r;
}
int main()
{
	int T,n,m;
	int kase = 0;
	scanf("%d",&T);
	while (T--){
		id = 0;
		cnt = 0;
		printf("Case %d:\n",++kase);
		scanf("%d%d",&n,&m);

		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[cnt++] = a[i];
		}

		for (int i = 0;i < m;++i){
			scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h);
			++q[i].r;
			b[cnt++] = q[i].h;
		}

		sort(b,b+cnt);
		cnt = unique(b,b+cnt) - b;
		for (int i = 1;i <= n;++i)
			a[i] = lower_bound(b,b+cnt,a[i]) - b + 1;
		for (int i = 0;i < m;++i)
			q[i].h = lower_bound(b,b+cnt,q[i].h) - b + 1;
		

		build(n);
		for (int i = 0;i < m;++i){	
			int ans = query(1,cnt,q[i].h,root[q[i].l],root[q[i].r]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
