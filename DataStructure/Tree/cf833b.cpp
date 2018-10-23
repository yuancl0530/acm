/*********************************
Date: Fri Sep  7 14:34:25 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 3e5 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int left,right,s,lazy;
}node[maxn*4];
int dp[maxn];
int build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].lazy = 0;
	if (left == right ) 
		return node[pos].s = dp[left];
	int mid = (left+right) >> 1;
	int l = build(left,mid,2*pos);
	int r = build(mid+1,right,2*pos+1);
	return node[pos].s = max(l,r);
}
void push(int pos)
{
	node[2*pos].lazy += node[pos].lazy;
	node[2*pos].s += node[pos].lazy;
	node[2*pos+1].lazy += node[pos].lazy;
	node[2*pos+1].s += node[pos].lazy;
	node[pos].lazy = 0;
}
int update(int left,int right,int v=1,int pos=1)
{
	if (left > node[pos].right || right < node[pos].left) return node[pos].s;
	if (left <= node[pos].left && node[pos].right <= right){
		node[pos].lazy += v;
		return node[pos].s += v;
	} 
	push(pos);
	int l = update(left,right,v,2*pos);
	int r = update(left,right,v,2*pos+1);
	return node[pos].s = max(l,r);
}

int query(int left,int right,int pos=1)
{
	if (left > node[pos].right || right < node[pos].left) return 0;
	if (left <= node[pos].left && node[pos].right <= right) return node[pos].s;
	push(pos);
	int l = query(left,right,2*pos);
	int r = query(left,right,2*pos+1);
	return max(l,r);
}
int a[maxn],pre[maxn],pos[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i) {
		scanf("%d",&a[i]);
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	for (int j = 1;j <= m;++j){
		build(0,n);
		for (int i = 1;i <= n;++i) {
			update(pre[i],i-1);
			dp[i] = query(0,i-1);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
