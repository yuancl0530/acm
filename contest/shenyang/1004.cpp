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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
int a[maxn];
int dp[maxn];
int f[maxn];
int main()
{
    int T,n,t,Max,Min,ans=0,k;
	scanf("%d",&T);
    while (T--){
		scanf("%d%d",&n,&k);
        Cl(dp,0x7f);
		Cl(f,0x7f);
		f[0]=-INF;
		dp[0] = -INF;
		f[0]=-INF;
		Max = 0;
		Min=0;
        for (int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        for (int i = 1 ;i <= n;i++){		
			t = lower_bound(dp+1,dp+n+1,a[i]) - dp;
			if (a[i]==dp[t])
				t++;
            Max = max(Max,t);
            dp[t] = min(dp[t],a[i]);
        }

        for (int i = 1 ;i <= n;i++){	
			t = lower_bound(f+1,f+n+1,a[n-i+1]) - f;
			if (a[n-i+1]==f[t])
				t++;
            Min = max(Min,t);
            f[t] = min(f[t],a[n-i+1]);
		}
		if (n-max(Min,Max)<=k)
        	printf("A is a magic array.\n");
		else
        	printf("A is not a magic array.\n");
    }
    return 0;
}
