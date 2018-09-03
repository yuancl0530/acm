#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 1e5 + 100;
vector<int>V[maxn];
long long ans[maxn], dis[maxn];
long long siz[maxn];
int k = 0;
void dfs(int last,int n)
{
    siz[n] = 1;
    for (int i = 0;i < V[n].size();i++){
        if (V[n][i] == last) continue;
        dfs(n,V[n][i]);
        siz[n] += siz[V[n][i]];
        dis[n] += dis[V[n][i]] + siz[V[n][i]];
    }
}
int N;
int dfs2(int last,int n,long long res)
{
    ans[n] = res + dis[n];
    for (int i = 0;i < V[n].size();i++){
        if (V[n][i] == last)continue;
        int y = V[n][i];
        long long  nres = res + dis[n] - dis[y] -siz[y] + (N - siz[y]);
        dfs2(n,V[n][i],nres);
    }
}
int main()
{

    int a;
    int b;
    ios::sync_with_stdio(false);
    while (cin >> N){
        memset(dis,0,sizeof dis);
        memset(ans,0,sizeof ans);
        memset(siz,0,sizeof siz);
        for(int i = 0;i < N;i++)
            V[i].clear();
        for (int i = 0;i < N-1;i++){
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dfs(0,1);
        dfs2(1,1,0);
        for (int i = 1;i <= N;i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
