/*********************************
Date: Wed Sep  5 22:48:18 CST 2018
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
	int left,right,s;
}node[4*maxn];
int a[maxn];
inline int nodemin(int x,int y)
{
	return a[node[x].s] < a[node[y].s] ? node[x].s : node[y].s;
}
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	if (left == right) {
		node[pos].s = left;
		return ;
	}
	int mid = (left+right) >> 1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
	node[pos].s = nodemin(2*pos,2*pos+1);
}

int query(int x,int pos = 1)
{
	if (node[pos].left == node[pos].right) 
		return node[pos].left;
	if (a[node[2*pos].s] <= x)
		return query(x,2*pos);
	return query(x,2*pos+1);
}
void update(int x,int pos=1)
{
	if (x == node[pos].left && node[pos].left == node[pos].right) {
		a[node[pos].left] = INF;
		return ;
	}
	int mid = (node[pos].left+node[pos].right) >> 1;
	if (x <= mid) update(x,2*pos);
	else update(x,2*pos+1);
	node[pos].s = nodemin(2*pos,2*pos+1);
}
int ans1[maxn],ans2[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i) scanf("%d",&a[i]);
	build(1,n);
	int cnt = 1;
	int res = m;
	for (int i = 1;a[node[1].s] != INF && i<= 100000;res+=m,++i,++cnt){
		ans1[i] = ans1[i-1];
		ans2[i] = res;
		while (a[node[1].s] != INF && a[node[1].s] <= res){
			int p = query(res);
			++ans1[i];
			ans2[i] -= a[p];
			res -= a[p];
			update(p);
		}
	}
	--cnt;
	int q,x;
	scanf("%d",&q);
	while (q--){
		scanf("%d",&x);
		if (x > cnt) x = cnt;
		printf("%d %d\n",ans1[x],ans2[x]);
	}
	return 0;
}
