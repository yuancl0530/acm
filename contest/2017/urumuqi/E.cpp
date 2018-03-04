/*********************************
Date: Sat Sep  9 13:36:53 CST 2017
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
LL f[]={1,8,49,288,1681,9800,57121,332928,1940449,11309768,65918161,384199200,2239277041,13051463048,76069501249,443365544448,2584123765441,15061377048200,87784138523761,511643454094368,2982076586042449,17380816062160328};
int main()
{
	int T;
	cin>>T;
	for (int t=1;t<=T;++t){
		LL n;
		scanf("%lld",&n);
		LL ans=-1;
		for (int i=0;i<22;i++){
			if (f[i]>=n){
				ans=f[i];
				break;
			}
		}
		printf("Case #%d: %lld\n",t,ans);
	}


	return 0;
}
