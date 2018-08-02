#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int graph[maxn][maxn];
int dis[maxn];
int n,m;
bool vs[maxn];
int prime()
{
    int ret = 0;
    int now = 1;
    int mincost;
    for (int i = 1;i <= n;i++){
        dis[i] = graph[now][i];
    }
    vs[now] = true;
    for (int i = 1;i <=n;i++){
        mincost = INF;
        for (int j = 1;j <= n;j++){
            if (!vs[j] && dis[j] < mincost){
                mincost = dis[j];
                now = j;
            }
        }
        if (mincost == INF)
            break;
        vs[now] = true;
        ret += mincost;
        for (int j = 1;j <=n;j++){
            if (!vs[j] && dis[j] > graph[now][j])
                dis [j] = graph[now][j];
        }
    }
    return ret;
}
int main()
{
    int f,t,d;
    while (scanf("%d%d",&n,&m) != EOF){
        memset(graph,0x3f,sizeof(graph));
        memset(vs,0,sizeof(vs));
        memset(dis,0,sizeof(dis));
        for (int i = 0;i < m;i++){
            scanf("%d%d%d",&f,&t,&d);
            graph[f][t] = min(graph[f][t],d);
            graph[t][f] = graph[f][t];
        }
        int ans = prime();

        printf("%d\n",ans);
    }

    return 0;
}
