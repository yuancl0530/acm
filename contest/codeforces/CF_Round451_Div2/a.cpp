/*********************************
Date: Sat Dec 16 19:35:31 CST 2017
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

int main()
{
    LL n;
    scanf("%lld",&n);
    LL ans;
    if (n%10==0)
        ans=n;
    else{
        LL n1=(n/10)*10;
        LL n2=(n/10+1)*10;
        ans=n1;
        if (n-n1 > n2-n)
            ans=n2;
    }
    printf("%lld\n",ans);

	return 0;
}
