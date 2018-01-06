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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[40][40];
bool vs[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	int t = 0;
	while (T--){
		bool flag = 0;
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				if (a[i][j] == a[i][j+1] || a[i][j] == a[i][j-1]
					|| a[i][j] == a[i+1][j] || a[i][j] == a[i-1][j])
						flag = 1;
			}
		}
		if (!flag){
			for (int i = 1;i <= m;i++){
				for (int j = i+1;j <= m;j++){
					if (a[1][i] == a[1][j] || a[n][i] == a[n][j]){
					
						flag = 1;
						break;
					}
				}
			}
			for (int i = 1;i <= n;i++){
				for (int j = i+1;j <= n;j++){
					if (a[i][1] == a[j][1] || a[i][m] == a[j][m]){
						flag = 1;
						break;
					}
				}
			}
		}
		printf("Case #%d: ",++t);
		if (flag){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
