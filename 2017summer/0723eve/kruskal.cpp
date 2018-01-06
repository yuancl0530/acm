#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int n,m;
const int maxn = 1e4+10;
struct Node
{
    int from;
    int to;
    int v;
}graph[5*maxn];
bool cmp(Node a,Node b){return a.v < b.v;}
int father[maxn];
int findF(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = findF(father[x]);
}
int kruskal()
{
    int ret = 0;
    for (int i = 0;i < m;i++){
        int n1 = findF(graph[i].from);
        int n2 = findF(graph[i].to);
        if (n1 != n2){
            ret += graph[i].v;
            father[n1] = n2;
        }
    }
    return ret;
}
int main()
{
    while (scanf("%d%d",&n,&m) != EOF){
        for (int i = 0;i < m;i++){
            scanf("%d%d%d",&graph[i].from,&graph[i].to,&graph[i].v);
        }
        for (int i = 1;i <= n;i++)
            father[i] = i;
        sort(graph,graph+m,cmp);
        int ans = kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
