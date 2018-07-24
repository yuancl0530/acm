#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn=1e5+100;
const LL INF=1e9+7;

int f[maxn],cost[maxn];
vector <int> edge[maxn];
int is_good[maxn];
int Time[maxn],timee[maxn][25];
LL limit[maxn][25];
int dp[maxn][25];
void dfs1(int x)
{
    if(is_good[x])
    {//printf("x=%d\n",x);
        Time[x]=0;
    }
    else
    {
        Time[x]=INF;
    }
    for(int i=0;i<edge[x].size();i++)
    {
        dfs1(edge[x][i]);
        //printf("edge[%d][%d]=%d\n",x,i,edge[x][i]);
        Time[x]=min(Time[x],Time[edge[x][i]]+1);
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n,m,Q,i,j,k,x,y,l,r,cnt,ans;
    scanf("%d",&T);
    while(T--)
    {

        //printf("T-");
        scanf("%d%d%d",&n,&m,&Q);
//        if(ca==98)
//        {
//            printf("%d %d %d\n",n,m,Q);
//        }
        for(i=1;i<=n;i++)
        {
            is_good[i]=0;
            edge[i].clear();
        }
        for(i=2;i<=n;i++)
        {
            scanf("%d",&f[i]);
            edge[f[i]].push_back(i);

        }
        for(i=2;i<=n;i++)
        {
            scanf("%d",&cost[i]);
            //printf("%d-%d cost=%d\n",f[i],i,cost[i]);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&x);
            is_good[x]=1;
        }
        //printf("ca=%d\n",ca);
        dfs1(1);
//        for(i=1;i<=n;i++)
//        {
//            printf("Time[%d]=%d\n",i,Time[i]);
//        }
        dp[1][0]=1;
        timee[1][0]=Time[1];
        //printf("A");
        for(i=2;i<=n;i++)
        {
            dp[i][0]=f[i];
            limit[i][0]=cost[i];///到终点的花费
            timee[i][0]=min(Time[i],Time[dp[i][0]]);///包括终点
        }
        for(j=1;j<=17;j++)
        {
            for(i=1;i<=n;i++)
            {
                dp[i][j]=dp[dp[i][j-1]][j-1];
                limit[i][j]=limit[i][j-1]+limit[dp[i][j-1]][j-1];
                timee[i][j]=min(timee[i][j-1],timee[dp[i][j-1]][j-1]);
            }
        }
        //printf("n=%d\n",n);
//        for(i=1;i<=n;i++)
//        {
//            for(j=0;j<=5;j++)
//            {
//                printf("limit[%d][%d]=%lld ",i,j,limit[i][j]);
//            }
//            printf("\n");
//        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=0;j<=5;j++)
//            {
//                printf("timee[%d][%d]=%lld ",i,j,timee[i][j]);
//            }
//            printf("\n");
//        }
        //printf("B");
        int p,up;
        LL Limit;
        while(Q--)
        {
            scanf("%d%lld",&p,&Limit);
            up=p;
            ans=Time[up];
            for(i=17;i>=0;i--)
            {
                if(limit[up][i]<=Limit)
                {
                    //printf("+timee[%d][%d]=%d\n",up,i,timee[up][i]);
                    Limit-=limit[up][i];
                    ans=min(ans,timee[up][i]);
                    up=dp[up][i];
                }
            }

            if(ans<INF)
            {
                printf("%d\n",ans);
            }
            else
            {
                printf("-1\n");
            }
        }
        //printf("C");
    }
    return 0;
}

