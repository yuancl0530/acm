#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 505;
int m[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    int n;
    while (scanf("%d",&n) != EOF){
        memset(m,0,sizeof m);
        memset(dp,0,sizeof(dp));
        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++)
                scanf("%d",&m[i][j]);
        }
        dp[0][0] = m[0][0];
        for (int i = 1;i < n;i++){
            dp[0][i] = dp[0][i-1] + m[0][i];
            dp[i][0] = dp[i-1][0] + m[i][0];
        }
        for (int i = 1;i < n;i++){
            for (int j = 1;j < n;j++)
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + m[i][j];
        }
        printf("%d\n",dp[n-1][n-1]);
    }
    return 0;
}
