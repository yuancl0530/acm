/*********************************
Date: Fri Sep  1 12:14:52 CST 2017
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int main()
{
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		LL ans=0;
		LL a,b,c,d;
		scanf("%I64d%I64d",&a,&b);
		if (a<b)swap(a,b);
		if (!b) {
			ans=1;
			if (a)ans++;
		}
		else if (a==b){
			ans=2;
		}
		else {
			d=a-b;
			while (d){
				ans+=a/d;
				LL t=d;
				d=a%d;
				a=t;
			}
			ans++;
		}
		printf("Case #%d: %I64d\n",tt,ans);
	}


	return 0;
}
