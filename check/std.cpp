#include <bits/stdc++.h>
using namespace std;

int q[105];
int e[105];
int dp[105][105][5];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
    e[1] = m;
    for(int i = 2; i <= n; i++) e[i] = e[i - 1] * 2 / 3;

    for(int i = 1; i <= n; i++)
    {
        dp[i][1][0] = min(q[i], e[1]);
        if(i > 2)
        {
            for(int j = 0; j <= i - 3; j++)
            {
                dp[i][1][0] = max(dp[i][1][0], dp[i - 3][j][0] + min(q[i], e[1]));
                dp[i][1][0] = max(dp[i][1][0], dp[i - 3][j][1] + min(q[i], e[1]));
            }
        }

        if(i > 1)
        {
            for(int j = 0; j <= i - 2; j++)
            {
                dp[i][0][1] = max(dp[i][0][1], dp[i - 2][j][0]);
                dp[i][0][1] = max(dp[i][0][1], dp[i - 2][j][1]);
            }
        }

        for(int j = 1; j <= i; j++)
        {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][0] + min(q[i], e[j]));
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
            if(i > 1)
                dp[i][j][0] = max(dp[i][j][0], dp[i - 2][j][0] + min(q[i], e[j]));
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        for(int k = 0; k < 2; k++)
            ans = max(ans, dp[i][j][k]); 
    }
    printf("%d\n", ans);
    return 0;
}
/*
900
600 40 400 20 266 10 177
*/
