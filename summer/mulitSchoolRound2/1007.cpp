/*********************************
Date: Wed Jul 25 19:49:11 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int left,right,v,lazy;
	ll s;
}node[4*maxn];
int b[maxn];
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].s = 0;
	node[pos].v = 0;
	node[pos].lazy = 0;
	if (left == right) {
		node[pos].v = b[left];
		return ;
	}
	int mid = (left+right) >> 1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
	node[pos].v = min(node[2*pos].v,node[2*pos+1].v);
}
void push_down(int pos)
{
	int t = 2*pos;
	node[t].v -= node[pos].lazy;
	node[t].lazy += node[pos].lazy;
	++t;
	node[t].v -= node[pos].lazy;
	node[t].lazy += node[pos].lazy;
	node[pos].lazy = 0;
}
void push_up(int pos)
{
	int t = pos<<1;
	node[pos].v = min(node[t].v,node[t+1].v);
	node[pos].s = node[t].s + node[t+1].s;
}
void dfs(int pos)
{
	if (node[pos].v > 0) return ;
	if (node[pos].left == node[pos].right){
		++node[pos].s;
		node[pos].v = b[node[pos].left];
		return ;
	}
	push_down(pos);
	dfs(2*pos);
	dfs(2*pos+1);
	push_up(pos);
}
void update(int left,int right,int pos=1,int v=1)
{
	if (node[pos].right < left || node[pos].left > right)	return ;
	if (left <= node[pos].left && node[pos].right <= right) {
		node[pos].lazy += v;
		node[pos].v -= v;
		if (node[pos].v <= 0)
			dfs(pos);
		return ;
	}
	push_down(pos);
	update(left,right,2*pos);
	update(left,right,2*pos+1);
	node[pos].v = min(node[2*pos].v,node[2*pos+1].v);
	node[pos].s = node[2*pos].s + node[2*pos+1].s;
}
ll query(int left,int right,int pos = 1)
{
	if (node[pos].right < left || node[pos].left > right) return 0;
	if (left <= node[pos].left && node[pos].right <= right) 
		return node[pos].s;
	push_down(pos);
	ll l = query(left,right,2*pos);
	ll r = query(left,right,2*pos+1);
	return l + r;
}
char op[10];
int main()
{
	int q,n,l,r;
	while (scanf("%d%d",&n,&q) != EOF){
		for (int i = 1;i <= n;++i)
			scanf("%d",&b[i]);
		build(1,n);
		while (q--){
			scanf("%s%d%d",op,&l,&r);
			if (op[0] == 'a')
				update(l,r);
			else
				printf("%lld\n",query(l,r));
			/*
			for (int i = 1;i <= 100;++i){
				if (node[i].left)
					printf("%d %d v=%d lazy=%d s=%lld\n",node[i].
					left,node[i].right,node[i].v,node[i].lazy,node[i].s);
			}
			*/
		}
	}
	return 0;
}
