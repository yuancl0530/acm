/*********************************
Date: Fri Aug  3 14:51:03 CST 2018
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
	int left,right,c;
	ll sum,lazy;
}node[maxn];
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].sum = 0;
	node[pos].lazy = 0;
	node[pos].c = 0;
	if (left == right){
		node[pos].c = left;
		return ;
	}
	int mid = (left+right) >> 1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
}
void push(int pos)
{
	if (!node[pos].lazy) return ;
	node[2*pos].lazy += node[pos].lazy;
	node[2*pos+1].lazy += node[pos].lazy;
	node[2*pos].c = node[2*pos+1].c = node[pos].c;
	node[pos].sum += node[pos].lazy*(node[pos].right-node[pos].left+1);
	node[pos].lazy = 0;
}
ll update(int left,int right,int c,int pos=1)
{
	if (left > node[pos].right || right < node[pos].left)
		return node[pos].sum + node[pos].lazy*(node[pos].right-node[pos].left+1);
	if (left <= node[pos].left && node[pos].right <= right && node[pos].c)
	{
		node[pos].lazy += abs(node[pos].c-c);
		node[pos].c = c;
		return node[pos].sum + node[pos].lazy*(node[pos].right-node[pos].left+1);
	}
	push(pos);
	ll l = update(left,right,c,2*pos);
	ll r = update(left,right,c,2*pos+1);
	node[pos].c = node[2*pos].c==node[2*pos+1].c? node[2*pos].c : 0;
	return node[pos].sum = l+r;
}
ll query(int left,int right,int pos=1)
{
	if (left > node[pos].right || node[pos].left > right) return 0;
	if (left <= node[pos].left && node[pos].right <= right)
		return node[pos].sum + node[pos].lazy*(node[pos].right-node[pos].left+1);
	push(pos);
	ll l =query(left,right,2*pos);
	ll r =query(left,right,2*pos+1);
	return l + r;
}
int main()
{
	int n,m,l,r,c,op;
	scanf("%d%d",&n,&m);
	build(1,n);
	while (m--){
		scanf("%d%d%d",&op,&l,&r);
		if (op==1) {
			scanf("%d",&c);
			update(l,r,c);
		}
		else
			printf("%lld\n",query(l,r));
	}
	return 0;
}
