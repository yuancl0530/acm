#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int left,right,pos,lazy,v;
}node[4*maxn];
int a[maxn];
int build(int left, int right, int pos=1)
{
	node[pos].left = left;
	node[pos].right  = right;
	node[pos].lazy = 0;
	if (left == right){
		node[pos].v  = a[left];
		return node[pos].v;
	}
	int mid =(left+right)>>1;
	int l = build(left,mid,2*pos);
	int r = build(mid+1,right,2*pos+1);
	return node[pos].v = max(l,r);
}
inline void push(int pos)
{
	if (!node[pos].lazy) return ;
	node[2*pos].lazy += node[pos].lazy;
	node[2*pos+1].lazy += node[pos].lazy;
	node[2*pos].v += node[pos].lazy;
	node[2*pos+1].v += node[pos].lazy;
	node[pos].lazy = 0;
}
int update(int l,int r,int v,int pos=1)
{
	if (l>node[pos].right || r<node[pos].left)
		return node[pos].v;
	if (l<=node[pos].left && node[pos].right<=r){
		node[pos].lazy += v;
		return node[pos].v+=v;
	}
	push(pos);
	int p = update(l,r,v,2*pos);
	int q = update(l,r,v,2*pos+1);
	return node[pos].v = max(p,q);
}
int query(int l,int r,int pos=1)
{
	if (l>node[pos].right || r<node[pos].left)
		return 0;
	if (l<=node[pos].left && node[pos].right<=r)
		return node[pos].v;
	push(pos);
	int p = query(l,r,2*pos);
	int q = query(l,r,2*pos+1);
	return max(p,q);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,n);
	int op;
	int x,y,v;
	while (m--){
		scanf("%d",&op);
		if (op){
			scanf("%d%d",&x,&y);
			printf("%d\n",query(x,y));
		}
		else{
			scanf("%d%d%d",&x,&y,&v);
			update(x,y,v);
		}
	}
	return 0;
}
