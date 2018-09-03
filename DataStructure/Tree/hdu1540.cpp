/*********************************
Date: Mon Jul 30 20:04:00 CST 2018
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
	int left,right;
	int lsum; //左连续
	int rsum; //右连续
	bool c; //全连续
}node[4*maxn];
int a[maxn];
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].c = true;
	node[pos].lsum = node[pos].rsum = right-left+1;
	if (left == right){
		a[left] = 1;
		return ;
	}
	int mid = (left+right) >> 1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
}
void update(int x,int v,int pos=1)
{
	if (x < node[pos].left || x > node[pos].right)
		return ;
	if (node[pos].left == node[pos].right){
		node[pos].lsum = node[pos].rsum = v;
		node[pos].c = v;
		a[x] = v;
		return ;
	}
	update(x,v,2*pos);
	update(x,v,2*pos+1);
	if (node[2*pos].c)
		node[pos].lsum = node[2*pos].lsum + node[2*pos+1].lsum;
	else
		node[pos].lsum = node[2*pos].lsum;
	if (node[2*pos+1].c)
		node[pos].rsum = node[2*pos+1].rsum + node[2*pos].rsum;
	else
		node[pos].rsum = node[2*pos+1].rsum;
	node[pos].c = node[pos].lsum >= (node[pos].right-node[pos].left+1);
}
int ans;
int query(int x,int pos = 1)
{
	if (x < node[pos].left || x > node[pos].right)
		return 0;
	if (node[pos].left == node[pos].right)
		return ans = node[pos].lsum;
	int l = query(x,2*pos);
	if (l){
		if (l == 1){
			ans += node[2*pos+1].lsum;
			if (node[2*pos+1].c) return 1;
			return 2;
		}
		if (l == 3){
			ans += node[2*pos+1].lsum;
			if (node[2*pos+1].c) return 3;
			return 4;
		}
		return l;
	}
	int r = query(x,2*pos+1);
	if (r){
		if (r == 1){
			ans += node[2*pos].rsum;
			if (node[2*pos].c) return 1;
			return 3;
		}
		if (r == 2){
			ans += node[2*pos].rsum;
			if (node[2*pos].c) return 2;
			return 4;
		}
		return r;
	}
	return 0;
}
int S[maxn];
int main()
{
	int n,m,x,y;
	char op[3];
	while(scanf("%d%d",&n,&m) != EOF){
		build(1,n);
		int top = - 1;
		while (m--){
			scanf("%s",op);
			if (op[0] == 'D'){
				scanf("%d",&x);
				update(x,0);
				S[++top] = x;
			}
			else if (op[0] == 'Q'){
				scanf("%d",&y);
				ans = 0;
				query(y);
				printf("%d\n",ans);
			}
			else
				update(S[top--],1);
		}
	}
	return 0;
}
