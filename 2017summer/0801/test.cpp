#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 1000000001
#define ll __int64
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN = 1000010;
struct node
{
    int flag;
    int val;
    int fa;
}a[MAXN];
int vis[MAXN];
int cnt;
int n,ans;
void bfs()
{
    queue<int>q;
    cnt = 1;
    a[0].fa = -1;
    a[0].flag = 1;
    a[0].val = 1;
    vis[1] = 1;
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(a[t].val == 0){
            ans = t;
            return;
        }
        a[cnt].flag = 0;
        a[cnt].val = (a[t].val * 10) % n;
        a[cnt].fa = t;
        if(!vis[a[cnt].val]){
            vis[a[cnt].val] = 1;
            q.push(cnt);
            cnt++;
        }
        a[cnt].flag = 1;
        a[cnt].val = (a[t].val * 10 + 1) % n;
        a[cnt].fa = t;
        if(!vis[a[cnt].val]){
            vis[a[cnt].val] = 1;
            q.push(cnt);
            cnt++;
        }
    }
}
void find(int p)
{
    if(p == -1)return;
    find(a[p].fa);
    printf("%d",a[p].flag);
}
int main()
{
    while(cin >>n){
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        memset(vis,0,sizeof(vis));
        bfs();
        find(ans);
        cout<<endl;
    }
}
