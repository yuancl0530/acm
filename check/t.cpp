/*********************************
Date: Wed Aug  8 21:14:49 CST 2018
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
const int maxn = 5e4 + 100;
struct { bool t;int l,r,k;} q[10010];
struct Node
{
	Node *left,*right;
	int sum;
}node[2500100],*root[maxn],*root1[maxn];
int a[maxn],b[60010],n,id,cnt;
Node *modify(int left,int right,int x,int v,Node *p)
{
	if (x < left || x > right ) return p;
	Node *t = &node[id++];
	*t = *p;
	t->sum += v;
	if (left == right) return t;
	int mid = (left+right)>>1;
	t->left = modify(left,mid,x,v,p->left);
	t->right = modify(mid+1,right,x,v,p->right);
	return t;
}
void update(int p,int x,int v)
{
	while (p <= n){
		root1[p] = modify(1,cnt,x,v,root1[p]);
		p += -p&p;
	}
}
vector<Node *>Q1,Q2;
int sum(const vector<Node*> &Q)
{
	int ret = 0;
	for (int i = 0;i < Q.size();++i)
		ret += Q[i]->left->sum;
	return ret;
}
int query(int left,int right,int k,Node *x,Node *y)
{
	if (left == right) return left;
	int mid = (left+right)>>1;
	int s = sum(Q2)-sum(Q1) + y->left->sum - x->left->sum;
	//cout<<left<<" "<<mid<<" "<<s<<" "<<sum(Q2)<<" "<<sum(Q1)<<endl;
	if (s >= k){
		for (int i = 0;i < Q1.size();++i) Q1[i] = Q1[i]->left;
		for (int i = 0;i < Q2.size();++i) Q2[i] = Q2[i]->left;
		return query(left,mid,k,x->left,y->left);
	}
	for (int i = 0;i < Q1.size();++i) Q1[i] = Q1[i]->right;
	for (int i = 0;i < Q2.size();++i) Q2[i] = Q2[i]->right;
	return query(mid+1,right,k-s,x->right,y->right);
}
int main()
{
	//freopen("in","r",stdin);
	int T,m;
	char op[2];
	scanf("%d",&T);
	while (T--){
		id = 0;
		cnt = 1;
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[cnt++] = a[i];
		}
		for (int i = 0;i < m;++i){
			scanf("%s",op);
			q[i].t = op[0]=='Q';
			if (q[i].t)
				scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
			else{
				scanf("%d%d",&q[i].l,&q[i].k);
				b[cnt++] = q[i].k;
			}
		}
		sort(b+1,b+cnt);
		cnt = unique(b+1,b+cnt) - b;
		for (int i = 1;i <= n;++i) 
			a[i] = lower_bound(b,b+cnt,a[i]) - b;
		for (int i = 0;i < m;++i)
			if (!q[i].t) q[i].k = lower_bound(b+1,b+cnt,q[i].k) - b;

		//static 
		root[0] = &node[id++];
		root[0]->left = root[0]->right = root[0];
		for (int i = 1;i <= n;++i)
			root[i] = modify(1,cnt,a[i],1,root[i-1]);
		// dynamic
		for (int i = 1;i <= n;++i) root1[i] = root[0];
		for (int i = 0;i < m;++i){
			if (q[i].t){
				int x = q[i].l - 1;
				int y = q[i].r;
				Q1.clear();
				Q2.clear();
				for (int i = x;i > 0;i -= -i&i) Q1.push_back(root1[i]);
				for (int i = y;i > 0;i -= -i&i) Q2.push_back(root1[i]);
				int pos = query(1,cnt,q[i].k,root[x],root[y]);
				printf("%d\n",b[pos]);
			}
			else{
				int x = q[i].l;
				update(x,a[x],-1);
				a[x] = q[i].k;
				update(x,a[x],1);
			}
		}
	}
	return 0;
}
