/*********************************
Date: Sat Dec 16 19:44:00 CST 2017
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
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0) {x=1,y=0;return a;}
    LL d=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
void solve(LL a,LL b,LL c)
{
    LL x,y;
    LL t=exgcd(a,b,x,y);
    if (c%t){
        printf("NO\n");
        return ;
    }
    x*=c/t;
    y*=c/t;
    while(x<0 && y>0){
        x+=b/t;
        y-=a/t;
    }
    while (x>0 && y<0){
        x-=b/t;
        y+=a/t;
    }
    if (x<0 || y<0){
        printf("NO\n");
        return ;
    }
    printf("YES\n%lld %lld\n",x,y);
}
int main()
{
    LL a,b,c;
    cin>>c>>a>>b;
    solve(a,b,c);
	return 0;
}
