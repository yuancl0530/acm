/*********************************
Date: Fri Aug 18 20:34:59 CST 2017
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
#define INF 0x7fffffff
#define Inf 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a,b,n;
int num[maxn];
int p[maxn],d[10];
LL dp[maxn][4];
int cnt=0;
int prime[maxn];
bool isprime[maxn];

priority_queue<int,vector<int>,greater<int> >Q;

void oula()
{
	Cl(isprime,1);
	for (int i = 2;i < maxn;i++){
		if (isprime[i])
			prime[++prime[0]]=i;
		for (int j=1;j<=prime[0];j++){
			int k = i*prime[j];
			if (k>=maxn)break;
			isprime[k]=0;
			if (i%prime[j]==0) break;
		}
	}
}
void getp()
{
	d[0]=num[1]-1,d[1]=num[1],d[2]=num[1]+1;
	d[3]=num[n]-1,d[4]=num[n],d[5]=num[n]+1;
	int Max = 0;
	for (int i= 0;i < 6;i++)
		Max = max(Max,d[i]);
	Max=sqrt(Max);
	for (int i=1;prime[i] <= Max;i++){
		for (int j = 0;j < 6;j++){
			if (d[j]&&d[j]%prime[i]==0){
				p[++cnt]=prime[i];
				while (d[j]%prime[i]==0){
					d[j]/=prime[i];
				}
			}
		}
	}
	//cout<<cnt<<endl;
	for (int i=0;i<6;i++)
		if (d[i]&&d[i]!=1)
			p[++cnt]=d[i];
}
LL Dp(int k)
{
	Cl(dp,0x7f);
	dp[1][1]=a;
	if (num[1]%k==0){
		dp[1][0]=0;
	}
	else if ((num[1]+1)%k==0 || (num[1]-1)%k==0){
		dp[1][0]=b;
	}
	int t;
	for (int i=2;i<=n;i++){
		t=num[i];
		if (t%k==0){
			dp[i][0]=dp[i-1][0];
		}
		else if ((t+1)%k==0 || (t-1)%k== 0){
			dp[i][0]=dp[i-1][0]+b;
		}
		dp[i][1]=dp[i-1][0]+a;
		dp[i][2]=min(dp[i-1][1],dp[i-1][2])+a;
		if (t%k==0){
			dp[i][3] = min(dp[i-1][1],min(dp[i-1][3],dp[i-1][2]));
		}
		else if ((t+1)%k==0 || (t-1)%k==0){
			dp[i][3] = min(dp[i-1][1],min(dp[i-1][3],dp[i-1][2])) + b;
		}
	}
	LL ret = min(dp[n][0],dp[n][3]);
	if (dp[n][2]!=(LL)n*a||a==b)
		ret = min(ret,dp[n][2]);
	if (dp[n][1]!=(LL)n*a||a==b)
		ret = min(ret,dp[n][1]);
	return ret;
}
int main()
{
	oula();
	while (scanf("%d%d%d",&n,&a,&b) != EOF){
		for (int i = 1;i <= n;i++)
			scanf("%d",&num[i]);
		getp();
		LL ans=Inf;
		for (int i = 1;i<=cnt;i++){
			ans = min(ans,Dp(p[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
