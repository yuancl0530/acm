/*********************************
Date: Wed Nov 22 16:43:47 CST 2017
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
const int maxn = 2e3 + 100;
int a[maxn],sum[maxn];
int dp[maxn][maxn],s[maxn][maxn];
int n;
int ans;
void solve()
{
	Cl(dp,0x77);
	for (int i=1;i<=2*n;++i){
		sum[i]=sum[i-1]+a[i];
		s[i][i]=i;
		dp[i][i]=0;
	}
	for (int len=2;len<=n;++len){
		for (int i=1;i+len-1<=2*n;++i){
			int j=i+len-1;
			dp[i][j]=INF;
			for (int k=s[i][j-1];k<=s[i+1][j];++k){
				int tmp=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
				if (tmp<dp[i][j]){
					dp[i][j]=tmp;
					s[i][j]=k;
				}
			}
		}
	}
	ans=dp[1][n];
	for (int i=1;i<=n+1;++i)
		ans=min(ans,dp[i][i+n-1]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	solve();
	printf("%d\n",ans);
	return 0;
}
