#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const long long inf = 1e10+100;
struct node
{
    int u,ti;
    long long w;
    node (int n1 = 0, long long n2 = 0, int n3 = 0)
    {
        u = n1, w = n2, ti = n3;
    }
    friend bool operator < (const node &n1, const node &n2)
    {
        return n1.w > n2.w;
    }
};
int T,n,m,k;
long long dp[maxn][15];
bool vis[maxn][15];
vector <node> e[maxn];

void solve()
{
    for (int i=1;i<=n+1;i++)
        for (int j=0;j<=k;j++)
    {
        dp[i][j] = inf;
        vis[i][j] = 0;
    }
    dp[1][0] = 0;
    vis[1][0] = 1;
    priority_queue <node> q;
    q.push(node(1,0,0));
    while (!q.empty())
    {
        int now = q.top().u;
        int tmp = q.top().ti;
        q.pop();
        if (tmp > k) continue;
        vis[now][tmp] = 1;
        //printf("i=%d j=%d %d\n",now,tmp,dp[now][tmp]);
        for (int i=0;i<e[now].size();i++)
        {
            int to = e[now][i].u;
            int val = e[now][i].w;

            if (dp[to][tmp+1] > dp[now][tmp])// 0
            {
                dp[to][tmp+1] = dp[now][tmp];
                if (vis[to][tmp+1]) continue;
                q.push(node(to,dp[to][tmp+1],tmp+1));
            }
            if (dp[to][tmp] > dp[now][tmp]+val)// val
            {
                dp[to][tmp] = dp[now][tmp]+val;
                if (vis[to][tmp]) continue;
                q.push(node(to,dp[to][tmp],tmp));
            }
        }

    }
    long long ans = inf;
    for (int i=0;i<=k;i++) ans = min(ans,dp[n][i]);
    printf("%lld\n",ans);
    return;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            e[u].push_back(node(v,w,0));
        }
        solve();
    }
    return 0;
}
