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
const int maxn = 1e3 + 100;
char a[maxn];
char b[maxn];
int dp[maxn][maxn];
void print(int x,int y)
{
	if (x == 0 || y == 0)
		return;
	if (a[x-1] == b[y-1]){
		print(x-1,y-1);
		printf("%c",a[x-1]);
	}
	else if (dp[x-1][y] >= dp[x][y-1]){
		print(x-1,y);
	}
	else{
		print(x,y-1);
	}
}
int main()
{
	while (scanf("%s%s",a,b) != EOF){
		int lena = strlen(a);
		int lenb = strlen(b);
		for (int i = 1;i <= lena;i++){
			for (int j = 1;j <= lenb;j++){
				dp[i][j] = max(dp[i-1][j-1]+(a[i-1]==b[j-1]),max(dp[i-1][j],dp[i][j-1]));
			}
		}
		print(lena,lenb);
		printf("\n");
	}
	return 0;
}
