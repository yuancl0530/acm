/*
编辑距离，又称Levenshtein距离（也叫做Edit Distance），是指两个字串之间，由一个转成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。给出两个字符串a,b，求a和b的编辑距离。
*/
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
#define CL(a) memset(a,0,sizeof(a))
const int maxn =  1e3 + 100;
char s[maxn],t[maxn];
int dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s){
        cin >> t;
        CL(dp);
        int lens = strlen(s);
        int lent = strlen(t);
        for (int i = 0;i <= lens;i++)
            dp[i][0] = i;
        for (int i = 0;i <= lent;i++)
            dp[0][i] = i;
        for (int i = 1;i <= lens;i++){
            for (int j = 1;j <= lent;j++){
                dp[i][j] = min(dp[i-1][j-1] + !(int)(s[i-1] == t[j-1]),min(dp[i-1][j] + 1,dp[i][j-1]+1));
            }
        }
        cout << dp[lens][lent]<<endl;
    }
    return 0;
}

