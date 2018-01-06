/*********************************
Date: Mon Oct  9 13:27:50 CST 2017
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
const int MOD = 1e8 + 7;
const int maxn = 1e4 + 100;
char s[maxn];
int dp[maxn],num[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%s",s);
		for (int i=0;s[i];++i)
			num[i+1]=s[i]-'0';
		int n=strlen(s);
		LL ans=0;
		for (int i=0;i<=min(num[1],2);++i){
			dp[1]=i;
			int j;
			for (j=2;j<=n;++j){
				dp[j]=num[j-1]-dp[j-1]-dp[j-2];
				if (dp[j]>2||dp[j]<0)
					break;
			}
			if (j<=n) continue ;
			if (num[n]!=dp[n-1]+dp[n])
				continue ;
			LL res=1;
			for (j=1;j<=n;++j){
				if (dp[j] == 1)
					res=2*res%MOD;
			}
			ans=(ans+res)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
