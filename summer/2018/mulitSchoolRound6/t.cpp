#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 1e5+50;
const int inf = 1e9;

vector<int> g[maxn];
bool c[maxn];
int n;
bool may[maxn];
bool must[maxn];
bool vis[maxn];
bool is_w[maxn];
int zhi[maxn];
char s[100];
int now;
bool ok;

void dfs0(int x)
{
    if (c[x]) return ;
    if (vis[x])
    {
        now = x;
        return ;
    }
    vis[x] = true;
    int v = zhi[x];
    dfs0(v);
    if (ok) c[x] = true;
    if (x == now) ok = false;
}

void dfs1(int x, int &cnt)
{
    if (vis[x])
    {
        if (cnt == 1)
            ok = true;
        return ;
    }
    vis[x] = true;
    int v = zhi[x];
    if (is_w[x]) cnt ++;
    dfs1(v, cnt);
    if (ok && is_w[x])
        must[v] = true;
}

void dfs2(int x)
{
    vis[x] = true;
    must[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        if (!vis[g[x][i]])
            dfs2(g[x][i]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        mst(may); mst(must); mst(vis); mst(is_w); mst(c);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d %s", zhi + i, s);
            if (s[0] == 'w') 
            {
                is_w[i] = true;
                may[zhi[i]] = true;
            }
            else
            {
                g[zhi[i]].push_back(i);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                ok = true;
                dfs0(i);
            }
        }
        mst(vis);
        //for (int i = 1; i <= n; ++i)
            //if (c[i]) printf(" %d %d\n", i, now);
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;
            if (c[i] && !vis[i])
                dfs1(i, cnt);
        }
        mst(vis);
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && must[i])
                dfs2(i);
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (must[i])
                ans ++;
        printf("0 %d\n", ans);
    }
    return 0;
}
