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
const int maxn = 6e4 + 100;
struct { bool t;int l,r,k;} q[10010];
struct Node
{
	int left,right;
	short sum;
}node[2550000];
int root[maxn],root1[maxn];
int a[maxn],b[maxn],n,id,cnt;
int modify(int left,int right,int x,int v,int p)
{
	if (x < left || x > right ) return p;
	int t = id++;
	node[t] = node[p];
	node[t].sum += v;
	if (left == right) return t;
	int mid = (left+right)>>1;
	node[t].left = modify(left,mid,x,v,node[p].left);
	node[t].right = modify(mid+1,right,x,v,node[p].right);
	return t;
}
int modify2(int left,int right,int x,int v,int p)
{
	if (x < left || x > right ) return p;
	int t;
	if (p == 0) {
		t = id++;
		node[t] = node[p];
	}
	else t = p;
	node[t].sum += v;
	if (left == right) return t;
	int mid = (left+right)>>1;
	node[t].left = modify(left,mid,x,v,node[p].left);
	node[t].right = modify(mid+1,right,x,v,node[p].right);
	return t;
}
void update(int p,int x,int v)
{
	while (p <= n){
		root1[p] = modify2(1,cnt,x,v,root1[p]);
		p += -p&p;
	}
}
vector<int>Q1,Q2;
int sum(const vector<int> &Q)
{
	int ret = 0;
	for (int i = 0;i < Q.size();++i)
		ret += node[node[Q[i]].left].sum;
	return ret;
}
int query(int left,int right,int k,int x,int y)
{
	if (left == right) return left;
	int mid = (left+right)>>1;
	int s = sum(Q2)-sum(Q1) +  node[node[y].left].sum - node[node[x].left].sum;// y->left->sum - x->left->sum;
	if (s >= k){
		for (int i = 0;i < Q1.size();++i) Q1[i] = node[Q1[i]].left;
		for (int i = 0;i < Q2.size();++i) Q2[i] = node[Q2[i]].left;
		return query(left,mid,k,node[x].left,node[y].left);
	}
	for (int i = 0;i < Q1.size();++i) Q1[i] = node[Q1[i]].right;
	for (int i = 0;i < Q2.size();++i) Q2[i] = node[Q2[i]].right;
	return query(mid+1,right,k-s,node[x].right,node[y].right);
}
int main()
{
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
		--cnt;
		//static 
		root[0] = id++;
		node[0].left = node[0].right = 0;
		node[0].sum = 0;
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
		//cout<<id<<" "<<tmp<<" "<<cnt<<endl;
	}
	return 0;
}
