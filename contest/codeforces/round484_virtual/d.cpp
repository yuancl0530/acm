/*********************************
Date: Thu May 31 15:01:07 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int fa[maxn],cnt[maxn],s[maxn];
int a[maxn];
struct Node
{
	int i,v;
	friend bool operator < (Node a,Node b)
	{
		return a.v < b.v;
	}
}b[maxn];
int getfa(int x)
{
	return x==fa[x]? x:getfa(fa[x]);
}
void link(int x, int y)
{
	x = getfa(x);
	y = getfa(y);
	if (x != y){
		--cnt[s[x]];
		--cnt[s[y]];
		fa[y] = x;
		s[x] += s[y];
		++cnt[s[x]];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		b[i].i = i;
		b[i].v = a[i];
		fa[i] = i;
	}
	sort(b+1,b+1+n);
	int mx = 0;
	int ans = 0;
	for (int i = 1;i <= n;++i){
		int x = b[i].i;
		int y = b[i].v;
		++cnt[s[i]=1];
		if (x != 1 && a[x-1] < a[x])
			link(x-1,x);
		if (x != n && a[x] > a[x+1])
			link(x+1,x);
		x = getfa(x);
		if (i == s[x]*cnt[s[x]]){
			if (cnt[s[x]] > mx){
				ans = y+1;
				mx = cnt[s[x]];
				//cout<<"*"<<endl;
			}
		}
		//printf("%d: %d\n",i,ans);
	}
	printf("%d\n",ans);
	return 0;
}
