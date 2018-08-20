/*********************************
Date: Wed Aug 15 12:41:55 CST 2018
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
int a[maxn];
int pre[maxn];
int cnt[maxn],s[maxn],cnt0[maxn];
int st[maxn][20],Log[maxn],n;
void init()
{
	for (int i = 1;i <= n;++i)
		st[i][0] = a[i];
	for (int j = 1;(1<<j) <= n;++j){
		for (int i = 1;i+(1<<j)-1 <= n;++i){
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int q_max(int l,int r)
{
	int t = Log[r-l+1];
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
int query(int x,int v)
{
	int l = x-1;
	int r = n+1;
	while (l+1<r){
		int mid = (l+r)>>1;
		if (v < q_max(x,mid)) r=mid;
		else l = mid;
	}
	return r;
}
int main()
{
	//freopen("./data/input","r",stdin);
	int T,m;
	for (int i =2;i < maxn;++i) Log[i] = Log[i>>1] + 1;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++i)
			scanf("%d",&a[i]);
		pre[1] = 0;
		pre[2] = 1;
		int k = 1;
		cnt0[1] = 1;
		for (int i = 2;i <= n;++i){
			if (a[i] > a[pre[i]]){
				cnt0[i] = cnt0[pre[i]] + 1;
				pre[i+1] = i;
				++k;
			}
			else{
				pre[i+1] = pre[i];
			}
		}

		int top = -1;
		a[0] = -1;
		a[n+1] = INF;
		s[++top] = n+1;
		cnt[n+1] = 0;
		for (int i = n;i >= 1;--i){
			while (top >= 0 && a[i] >= a[s[top]]) --top;
			cnt[i] = cnt[s[top]] + 1;
			s[++top] = i;
		}
		int p,q;
		init();
		while (m--){
			scanf("%d%d",&p,&q);
			int nl = cnt0[pre[p]];
			int ans = k;
			int y = pre[p];
			if (a[y] >= q){
				int x = query(p+1,a[y]);
				ans = nl + cnt[x];
			}
			else if (a[y] < q){
				int x = query(p+1,q);
				ans = nl + cnt[x] + 1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
