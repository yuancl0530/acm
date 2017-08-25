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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL dp[maxn];
int pos[maxn];
int main()
{
    int n,now;
    dp[0]=1;
	while (scanf("%d",&n) != EOF){
		CL(pos);
		for(int i=1;i<=n;i++){
        	scanf("%d",&now);
			dp[i]=(dp[i-1]*2)%MOD;
        	if (pos[now]){
         	   dp[i]=(dp[i] -dp[pos[now]-1] + MOD) % MOD;
			}
			pos[now] = i;
    	}
    	printf("%lld\n",dp[n]-1);
	}
    return 0;
}

