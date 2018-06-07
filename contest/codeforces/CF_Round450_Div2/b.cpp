/*********************************
Date: Wed Dec 13 13:28:40 CST 2017
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
int f[maxn];
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans=-1;
    f[a]=1;
    for (int i=1;;++i){
        a*=10;
        int t=a/b;
        a%=b;
        if (t==c){
            ans=i;
            break;
        }
        if (f[a]) break;
        f[a]++;
    }
    printf("%d\n",ans);
	return 0;
}
