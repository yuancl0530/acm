#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

using namespace std;

const int maxn = 1e4;
int T,n,m,dp[maxn];
char a[maxn],b[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        n = strlen(a+1);
        m = strlen(b+1);
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int j=1;j<=m;j++)
        {
            if (b[j] == '*') continue;
            if (b[j+1] == '*')
            {
                for (int i=0;i<=n;i++)
                    if (dp[i] && (b[j]=='.' || b[j] == a[i+1]))
                        dp[i+1] = 1;
            }
            else
            {
                for (int i=n;i>=0;i--)
                {
                    if (dp[i] && (b[j]=='.' || b[j] == a[i+1]))
                        dp[i+1] = 1;
                    dp[i] = 0;
                }
            }
        }
        if (dp[n]) printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
