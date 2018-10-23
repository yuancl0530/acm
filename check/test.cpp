/**
    Author : Dsy
**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

#define bll long long

const int maxm = 2e4+100;
int a[110],dp[110][maxm];

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=m;j++) dp[i][j] = -1;
        dp[0][m] = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<=m;j++)
            {
                //if (dp[i][j] == -1) continue;
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);  // stop 1 hour

                dp[i+2][m] = max(dp[i+2][m],dp[i][j] + min(m,a[i+2]));  // stop 2 hours

                dp[i+1][j*2/3] = max(dp[i+1][j*2/3] , dp[i][j] + min(j*2/3,a[i+1]));
            }
        int ans = 0;
        for (int j=0;j<=m;j++) ans = max(ans,dp[n][j]); 
        printf("%d\n",ans);
    }
    return 0;
}
