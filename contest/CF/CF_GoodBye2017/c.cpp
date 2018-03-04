/*********************************
Date: Sat Dec 30 00:28:08 CST 2017
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
int cx[maxn];
double cy[maxn];
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    for (int i=0;i<n;++i)
        scanf("%d",&cx[i]);
    for (int i=0;i<n;++i){
        double t = r;
        for (int j=0;j<i;++j){
            if (abs(cx[i]-cx[j])<=2*r){
                t=max(t,cy[j]+sqrt(4*r*r-(cx[i]-cx[j])*(cx[i]-cx[j])));
            }
        }
        cy[i]=t;
        printf("%lf ",cy[i]);
    }
    printf("\n");
	return 0;
}
