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
bool check(char a)
{
	if (a == 'A' || a=='I'||a == 'H' || a == 'M' || a == 'O' || a == 'T'
	|| a == 'U' || a== 'V' || a == 'W' || a == 'X' || a == 'Y')
		return true;
	return false;
}
char a[maxn];
int dp[maxn][maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--){
		int ans = 0;
		CL(dp);
		CL(a);
		scanf("%s",a);
		int lena = strlen(a);
		for (int i = 1;i <=lena;i++){
			if (check(a[i-1])){
				dp[i][i] = 1;
			}
			else{
				dp[i][i] = 0;
			}
		}
		for (int len = 2;len <= lena;len++){
			for (int i = 1;i < lena;i++){
				int j = i + len - 1;
				if ((a[i-1] == a[j-1])&& check(a[i-1])){
				//	cout << a[i-1] <<endl;
					if (dp[i+1][j-1] == 1 || i+1==j){
						dp[i][j] = 1;
						ans = max(ans,len);
					}
					else{
						dp[i][j] = 0;
					}
				}
			}
		}
		printf("%d\n",ans);
	
	}
	return 0;
}
