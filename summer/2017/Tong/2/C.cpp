/*********************************
Date: Thu Aug 24 09:56:50 CST 2017
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL dp[30][3];//0 no 49,1 with 9 first but no 49,2 with 49
int bit[30];
void init()
{
	dp[0][0]=1;
	for (int i=1;i<=21;i++){
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
	}
}
int main()
{
	init();
	LL n;
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%lld",&n);
		int cnt=0;
		n++;
		while (n){
			bit[++cnt]=n%10;
			n/=10;
		}
		LL ans=0;
		int last=-1;
		bool flag=0;
		for (int i=cnt;i>0;i--){
			ans+=bit[i]*dp[i-1][2];
			if (flag){
				ans+=bit[i]*dp[i-1][0];
			}
			if (!flag && bit[i]>4){
				ans+=dp[i-1][1];
			}
			if (last==4&&bit[i]==9){
				flag=1;
			}
			last=bit[i];
		}
		printf("%lld\n",ans);
	}


	return 0;
}
