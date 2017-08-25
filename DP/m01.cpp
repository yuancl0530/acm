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
#define YOUHUA 1
const int maxn = 5e4 + 100;
int w[maxn];
int c[maxn];
int p[maxn];
int dp[110][maxn];
int f[maxn];
int main()
{
	int n,m;
	while (cin >> n >>m){
		for (int i = 1;i <= n;i++){
			cin >> w[i] >> p[i] >>c[i];
		}
#if YOUHUA==0 //优化前
		for (int i = 1;i <= n;i++){
        	for (int j = 1;j <= m;j++){
            	for (int k = 0;k <= c[i] && k*w[i] <=j;k++){
                	dp[i][j] = max(dp[i][j],dp[i-1][j-k*w[i]] + k*p[i]);
        		}
        	}
		}
		cout << dp[n][m] << endl;
#else		 //优化后
	   for (int i = 1;i <= n;i++){
        	for (int j = m;j >= w[i];j--){
            	for (int k = 1;k <= c[i] && k*w[i] <=j;k++){
                	f[j] = max(f[j-k*w[i]]+k*p[i],f[j]);
                }
            }
    	}
		cout << f[m] << endl;
#endif
	}
	return 0;
}
