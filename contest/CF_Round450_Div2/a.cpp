/*********************************
Date: Wed Dec 13 13:21:43 CST 2017
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
    int l=0;
    int r=0;
    int x,y;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        if (x>0) r++;
        else l++;
    }
    if (l<=1 || r<=1)
        printf("Yes\n");
    else
        printf("No\n");
	return 0;
}
