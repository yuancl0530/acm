/*********************************
Date: Tue May 29 14:31:32 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
int x[maxn],y[maxn];
int mto[maxn][20];
int cost[maxn][20];
int Log[maxn], n;
int S[maxn];
int bsearch(int v)
{
	int l = 0;
	int r = n+1;
	while (l+1 <r){
		int mid = (l+r)>>1;
		if (v < x[mid])
			r = mid;
		else
			l = mid;
	}
	return r;
}
void init()
{
	int top = -1;
	x[n+1] = INF;y[n+1] = 0;
	S[++top] = n+1;
	mto[n+1][0] = n+1;
	for (int i = n;i>0;--i){
		int t = bsearch(x[i]+y[i]);
		mto[i][0] = t;
		if (t!=n+1) cost[i][0] = x[t] - x[i] -y[i];
	}
	for (int j = 1;j < 20;++j){
		for (int i = 1;i <= n+1;++i){
			mto[i][j] = mto[mto[i][j-1]][j-1];
			cost[i][j] = cost[i][j-1] + cost[mto[i][j-1]][j-1];
		}
	}
}
int query(int l,int r)
{
	int ans = 0;
	for (int i = 19;i >= 0;--i){
		if (mto[l][i] <= r){
			ans += cost[l][i];
			l = mto[l][i];
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i =1;i <= n;++i)
		scanf("%d%d",&x[i],&y[i]);
	init();
	int q;
	scanf("%d",&q);
	int l,r;
	while (q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
