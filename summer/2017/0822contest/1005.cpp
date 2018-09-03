/*********************************
Date: Tue Aug 22 14:31:40 CST 2017
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 100;
vector<int>V[maxn];
int n,m;
int ans;
bool vs[maxn];
int deg[maxn];
bool used[maxn][maxn];
void dfs(int x,int cnt=1)
{
    if (ans||cnt==n){ans = 1;return;}
    for (int i=0;i<V[x].size();i++){
		if (used[x][V[x][i]])continue;
		used[x][V[x][i]]=1;
        dfs(V[x][i],cnt+1);
		used[x][V[x][i]]=0;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int u,v;
    while (T--){
        scanf("%d%d",&n,&m);
        CL(deg);
        for (int i=1;i<=n;i++)V[i].clear();
        for (int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            V[u].push_back(v);
            deg[u]++;
        }
        ans=0;
        for (int i=1;i<=n;i++){
            CL(vs);
            if (!deg[i])continue;
            dfs(i);
            if (ans)break;
        }
        if (ans)
            printf("I love you my love and our love save us!\n");
        else
            printf("Light my fire!\n");
    }
    return 0;
}
