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
#define YOUHUA 0
const int maxn = 1e4 + 10;
int w[maxn];
int p[maxn];
int dp[110][maxn];
int f[maxn];
int main()
{
	int n,m;
	ios::sync_with_stdio(false);
    while (cin >> n){
        cin >> m;
        for (int i =1;i <= n;i++)
            cin >> w[i] >> p[i];
#if YOUHUA==0 //优化后
        for (int i = 1;i <= n;i++){
        	for (int j = 1;j <= m;j++){
        	    if (j >= w[i]){
         	       dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + p[i]);
         	   }
       	    	else {
                	dp[i][j] = dp[i-1][j];
            	}
       		}
   		}
		cout << dp[n][m] <<endl;
#else        //优化前
	    for (int i = 1;i <= n;i++){
            for (int j = m;j >= w[i];j--){
                f[j] = max(f[j],f[j-w[i]] + p[i]);
            }
        }
        cout << f[m] <<endl;
#endif
	}
	return 0;
}
