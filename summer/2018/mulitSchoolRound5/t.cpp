/*********************************
Date: Mon Aug  6 12:53:36 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
unsigned int X,Y,Z;
unsigned int  fun()
{
    X = X^(X<<11);
    X = X^(X>>4);
    X = X^(X<<5);
    X = X^(X>>14);
    ll W = X^Y^Z;
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}
unsigned int  f[15*maxn];
struct Q
{
    int l,r;
	unsigned int v;
    friend bool operator<(Q a,Q b)
    {
        return a.v < b.v;
    }
}q[5*maxn];
struct Node
{
    int left,right;
    unsigned int  v,lazy;
}node[maxn];
ll a[maxn];
void build(int left,int right,int pos=1)
{

    node[pos].left = left;
    node[pos].right = right;
    node[pos].v = node [pos].lazy = 0;
    if (left == right) return ;
    int mid = (left+right)>>1;
    build(left,mid,2*pos);
    build(mid+1,right,2*pos+1);
}
void push(int pos)
{
    if (node[pos].lazy==0) return ;
    node[2*pos].lazy = node[2*pos].v = node[pos].lazy;
    node[2*pos+1].lazy = node[2*pos+1].v = node[pos].lazy;
    node[pos].lazy = 0;
}
void update(int left,int right,unsigned int v,int pos=1)
{
    if (right < node[pos].left || left > node[pos].right) return ;
    if (left <= node[pos].left && node[pos].right <= right){
        node[pos].v = node[pos].lazy = v;
        return ;
    }
    push(pos);
    update(left,right,v,2*pos);
    update(left,right,v,2*pos+1);
	node[pos].v = min(node[2*pos].v,node[2*pos+1].v);
}
void dfs(int pos=1)
{
    if (node[pos].left == node[pos].right){
        a[node[pos].left] = node[pos].v;
        return ;
    }
    push(pos);
    dfs(2*pos);
    dfs(2*pos+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    while (T--){
        scanf("%d%d%u%u%u",&n,&m,&X,&Y,&Z);
        for (int i = 1;i <= 3*m;++i) {
			if (i%3 == 0) f[i] = fun()%(1u<<30);
			else f[i] = fun()%(unsigned int )n;
		}
        for (int i = 1;i <= m;++i){
            q[i].l = min(f[3*i-2]+1,f[3*i-1]+1);
            q[i].r = max(f[3*i-2]+1,f[3*i-1]+1);
            q[i].v = f[3*i];
        }
        build(1,n);
        /*sort(q+1,q+1+m);
        for (int i = 1;i <= m;++i) update(q[i].l,q[i].r,q[i].v);
        dfs();
        ll ans = 0;
        for (int i = 1;i <= n;++i) ans ^= a[i]*i;
        printf("%lld\n",ans);*/
    }
    return 0;
}
