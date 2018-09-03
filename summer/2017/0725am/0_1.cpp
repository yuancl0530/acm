#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
const int INF= 0x7fffffff;
const int maxn = 1e4 + 100;
int  dp[maxn];
int w[maxn],p[maxn];
int main()
{
    int n,W;
    while (cin >> n >> W){
        for (int i = 1;i <= n;i++)
            cin >> w[i] >> p[i];
        for (int i = 1;i <= n;i++){
            for (int j = W  ;j >= w[i];j--){
                if (j >= w[i])
                    dp[j] = max(dp[j],dp[j-w[i]] + p[i]);

           //     cout <<i<<","<<j<<' '<< dp[j]<<endl;
            }
        }
        printf("%d\n",dp[W]);
    }
    return 0;
}
