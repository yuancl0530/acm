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
#define LL long long
const int INF= 0x7fffffff;
const int maxn = 1e3 + 100;
long long dp[maxn][maxn];
char a[maxn];
char b[maxn];

int main()
{
    while (cin >> a){
        cin >> b;
        int lena = strlen(a);
        int lenb = strlen(b);
        CL(dp);
        for (int i = 1;i <= lena;i++)
            dp[i][0] = i;
        for (int i = 1;i <= lenb;i++)
            dp[0][i] = i;
        for (int i = 1;i <= lena;i++){
            for (int j = 1;j <= lenb;j++){

                dp[i][j] = min(dp[i-1][j-1] + !(a[i-1] == b[j-1]),min(dp[i-1][j]+1,dp[i][j-1]+1));

            }
        }
        cout << dp[lena][lenb] << endl;
    }
    return 0;
}
