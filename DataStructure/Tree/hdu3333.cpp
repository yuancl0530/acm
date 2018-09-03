/*********************************
Date: Tue Aug 21 16:27:25 CST 2018
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
const int maxn = 3e5 + 100;
int a[maxn],b[maxn],last[maxn];
struct Q
{
	int l,r,id;
	ll ans;
}q[maxn];
bool cmp1(Q a,Q b) {return a.l > b.l;}
bool cmp2(Q a,Q b) {return a.id < b.id;}
struct Node
{
	int left,right;
	ll sum;
}node[4*maxn];
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].sum = 0;
	if (left == right) return ;
	int mid = (left+right)>>1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
}
void update(int x,ll v,int pos=1)
{
	if (x < node[pos].left || x > node[pos].right) return ;
	node[pos].sum += v;
	update(x,v,2*pos);
	update(x,v,2*pos+1);
}
ll query(int left,int right,int pos=1)
{
	if (left > node[pos].right || right < node[pos].left ) return 0;
	if (left <= node[pos].left && node[pos].right <= right) return node[pos].sum;
	return query(left,right,2*pos) + query(left,right,2*pos+1);
}
int main()
{
	int T,m,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int cnt = 1;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[cnt++] = a[i];
			last[i] = 0;
		}
		sort(b+1,b+cnt);
		cnt = unique(b+1,b+cnt) - b;
		for (int i = 1;i <= n;++i) a[i] = lower_bound(b+1,b+cnt,a[i]) - b;
		scanf("%d",&m);
		for (int i = 0;i < m;++i){
			scanf("%d%d",&q[i].l,&q[i].r);
			q[i].id = i;
		}
		sort(q,q+m,cmp1);
		q[m].l = -1;
		int t = 0;
		build(1,n);
		for (int i = n;i >= 1;--i){
			if (last[a[i]]) update(last[a[i]],-b[a[i]]);
			last[a[i]] = i;
			update(i,b[a[i]]);
			while (q[t].l == i){
				q[t].ans = query(1,q[t].r);
				++t;
			}
		}
		sort(q,q+m,cmp2);
		for (int i = 0;i < m;++i)
			printf("%lld\n",q[i].ans);
	}
	return 0;
}
