#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e4+7;
const LL mod = 998244353;
const int INF=1e9+2e7;

LL dp[maxn][35];
LL dp2[maxn][35];
LL to[maxn][35];
LL a[maxn];
int main()
{
    LL n,m,i,j,x,y,len,ans,Case=0,S,K,M,ans2;
    LL T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&n,&S,&M,&K);
        M--;
        for(i=0;i<n;i++) scanf("%lld",&a[i]);
        ans=0;
        for(i=0;i<n;i++) ans=max(ans,a[i]);
        m=0;
        x=1;
        while((x<<1)<=M) {x<<=1;m++;}
        //printf("m=%lld\n",m);
        for(i=0;i<n;i++)
        {
            dp2[i][0]=a[i]+a[(i+K)%n];
            dp[i][0]=max(a[i],dp2[i][0]);
            to[i][0]=(i+K)%n;
        }
        for(j=1;j<=m;j++)
        {
            for(i=0;i<n;i++)
            {
                to[i][j]=to[to[i][j-1]][j-1];
                dp2[i][j]=dp2[i][j-1]+dp2[to[i][j-1]][j-1]-a[to[i][j-1]];
                dp[i][j]=max(dp[i][j-1],dp2[i][j-1]+dp[to[i][j-1]][j-1]-a[to[i][j-1]]);
//                printf("to[%lld][%lld]=%lld ",i,j,to[i][j]);
//                printf("dp2[%lld][%lld]=%lld ",i,j,dp2[i][j]);
//                printf("dp[%lld][%lld]=%lld \n",i,j,dp[i][j]);
            }
        }
        ans2=0;
        for(i=0;i<n;i++)
        {
            y=0;///表示跳了多少步
            x=i;///x是当前位置
            ans2=a[i];
            for(j=m;j>=0;j--)
            {
                if(y+(1<<j)>M) continue;
                ans=max(ans,ans2+dp[x][j]-a[x]);
                ans2=ans2+dp2[x][j]-a[x];
                y+=(1<<j);
                x=to[x][m];
            }
        }
        //printf("ans=%lld\n",ans);
        if(ans>S) ans=0;
        else ans=S-ans;
        printf("Case #%lld: %lld\n",++Case,ans);
    }
    return 0;
}

/**
2
5 20 6 3
2 3 2 1 5
3 10 5 2
3 2 1

**/
