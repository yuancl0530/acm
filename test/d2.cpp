/*********************************
Date: Tue Jan 30 21:48:16 CST 2018
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
int main()
{
	int t,n,k,cnta,cntb;
	cnta=cntb=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%d",&t);
		if (t<0)
			b[cntb++] = t;
		else
			a[cnta++] = t;
	}
	sort(b,b+cntb);
	for (int i=0;i<cntb;++i){
		if (k){
			a[cnta++] = -b[i];
			--k;
		}
		else
			a[cnta++] = b[i];
	}
	sort(a,a+cnta);
	if (k&1) a[0] = -a[0];
	LL ans = 0;
	for (int i=0;i<cnta;++i)
		ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}
