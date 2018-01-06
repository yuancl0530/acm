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
const int maxn = 5e3 + 10;
int dp[maxn];
char a[maxn];
int main()
{
	while (scanf("%s",a) != EOF){
		int lena = strlen(a);
		int left;
		int right;
		Cl(dp,0x7f);
		dp[0] = 0;
		for (int i = 1;i <= lena;i++){
			left = i;
			right = i + 1;
			while (left > 0 && right <= lena && a[left-1] == a[right-1]){
				dp[right] = min(dp[right],dp[left-1] + 1);
				left--;
				right++;

			}			
			left = right = i; // 奇数
			while (left > 0 && right <= lena && a[left-1] == a[right-1]){
				dp[right] = min(dp[right],dp[left-1] + 1);
				left--;
				right++;

			}
		}
		/*for (int i = 1;i <= lena;i++){
			printf("dp[%d] = %d\n",i,dp[i]);
		}*/
		printf("%d\n",dp[lena]);

	}
	return 0;
}
