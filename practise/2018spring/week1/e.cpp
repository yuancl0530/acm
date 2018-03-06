/*********************************
Date: Tue Mar  6 22:06:42 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn],b[maxn];
LL s[maxn];
LL sa=0;
LL t[maxn];
int cnt=0;
LL b_search(LL a)
{
	int l=0;
	int r=cnt;
	while (l+1<r){
		int mid = (l+r)>>1;
		if (t[mid] <= a)
			l = mid;
		else
			r = mid;
	}
	return l;
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (i&1)
			sa+=a[i];
		else
			sa-=a[i];
	}
	for (int i=1;i<=m;++i){
		scanf("%d",&b[i]);
		if (i&1)
			s[i] = s[i-1]+b[i];
		else
			s[i] = s[i-1]-b[i];
	}
	for (int i=1;i+n-1<=m;++i){
		if (i&1)
			t[cnt++] = s[i+n-1] - s[i-1];
		else
			t[cnt++] = s[i-1] - s[i+n-1];
	}
	sort(t,t+cnt);
	LL ans ;
	cnt = unique(t,t+cnt) - t;
	int tmp = b_search(sa);
	ans = abs(sa-t[tmp]);
	if (tmp+1<cnt)
		ans = min(ans,abs(sa-t[tmp+1]));
	printf("%lld\n",ans);
	for (int i=0;i<q;++i){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if ((r-l+1)%2==1){
			if (l&1)
				sa+=x;
			else
				sa-=x;
		}
		tmp = b_search(sa);
		ans = abs(sa-t[tmp]);
		if (tmp+1<cnt)
			ans = min(ans,abs(sa-t[tmp+1]));
		printf("%lld\n",ans);
	}
	return 0;
}
