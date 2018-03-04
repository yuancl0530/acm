/*********************************
Date: Wed Dec 20 12:30:29 CST 2017
Author: ycl
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int tot[maxn];
int a[maxn];
int nn=1e6;
int lowbit(int x)
{
    return -x&x;
}
int sum(int t)
{
    int ret=0;
    while (t>=1){
        ret+=tot[t];
        t-=lowbit(t);
    }
    return ret;
}
void update(int t,int v)
{
    while (t<=nn){
        tot[t]+=v;
        t+=lowbit(t);
    }
}
void sub(int l,int r,int t)
{
    int i=r;
    while (t){
        if (a[i]){
            a[i]=0;
            update(i,-1);
            --t;
        }
        --i;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int t;
    for (int i=0;i<n;++i){
        scanf("%d",&t);
        update(t,1);
        a[t]=1;
    }
    int ans=0;
    for (int i=1;i<=nn;++i){
        int r=i+m-1;
        r=min(r,nn);
        int s=sum(r)-sum(i-1);
        if (s>=k){
            sub(i,r,s-k+1);
            ans+=s-k+1;
        }
    }
    printf("%d\n",ans);
	return 0;
}
