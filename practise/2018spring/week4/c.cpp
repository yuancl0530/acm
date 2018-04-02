/*********************************
Date: Mon Mar 26 22:30:09 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
#define N 100000
int n;
int tot[maxn];
int num1[maxn],num2[maxn],a[maxn];
inline int lowbit(int x) {return -x&x;}
void update(int pos,int v)
{
	for (;pos<=N;pos+=lowbit(pos)){
		tot[pos]+=v;
	}
}
int sum(int pos)
{
	int ret=0;
	for (;pos>0;pos-=lowbit(pos)){
		ret+=tot[pos];
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		CL(tot);
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			num1[i]=sum(a[i]);
			update(a[i],1);
		}
		CL(tot);
		for (int i=n;i>0;--i){
			num2[i]=sum(a[i]-1);
			update(a[i],1);
		}

		LL ans=0;
		for (int i=1;i<=n;++i){
			ans+=(LL)num1[i]*(n-i-num2[i]);
			ans+=(LL)(i-1-num1[i])*num2[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
