/*********************************
Date: Sun Nov 19 13:25:50 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL p[maxn];
int a[maxn],n;
LL b[maxn];
int getP(LL s)
{
	int cnt=0;
	int t=sqrt(s);
	for (int i=2;i<=t;++i){
		if (s%i==0)
			p[cnt++]=i;
		while (s && s%i==0)
			s/=i;
		if (s==1) break;
	}
	if (s>1)
		p[cnt++]=s;
	return cnt;
}
LL solve(LL p)
{
	LL sum=0;
	for (int i=0;i<n;++i){
		b[i]=a[i]%p;
		sum+=b[i];
	}
	sort(b,b+n);
	int t=sum/p;
	LL ans=0;
	for (int i=n-1;i>=n-t;--i)
		ans+=p-b[i];
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		LL sum=0;
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			sum+=(LL)a[i];
		}
		int cnt=getP(sum);
		LL ans=sum;
		for (int i=0;i<cnt;++i){
			ans=min(ans,solve(p[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
