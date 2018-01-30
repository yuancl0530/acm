/*********************************
Date: Wed Dec 13 13:35:37 CST 2017
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
int n;
int tot[maxn];
int lowbit(int x)
{
    return -x&x;
}
int sum(int m)
{
    int ret=0;
    while (m>0){
        ret+=tot[m];
        m-=lowbit(m);
    }
    return ret;
}
int update(int m)
{
    while (m<=n){
        tot[m]++;
        m+=lowbit(m);
    }

}
int a[maxn];
int f[maxn],p[maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int Max=a[1];
    update(a[1]);
    p[a[1]]=1;
    for (int i=2;i<=n;++i){
        update(a[i]);
        int t=i-sum(a[i]);
        if (t==1)
            f[Max]++;
        else if(t==0)
            p[a[i]]=1;
        Max=max(Max,a[i]);
    }
    int ans=1;
    for (int i=2;i<=n;++i){
        if (f[a[ans]]-p[a[ans]] < f[a[i]] - p[a[i]])
            ans=i;
        else if (f[a[ans]]-p[a[ans]] == f[a[i]] - p[a[i]] && a[i] < a[ans])
            ans=i;
    }
    printf("%d\n",a[ans]);
   
	return 0;
}
