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
char G[110][110];
int ly,ry,ux,dx;
int dxx[] = {-1,1,0,0};
int dyy[] = {0,0,-1,1};
int cnt = 0;
int n,m;
bool vs[110][110];

int main()
{
	while (scanf("%d%d",&n,&m) != EOF){
		int ans = n*m + 1;
		for (int i = 0;i < n;i++)
			scanf("%s",G[i]);
		int sum = 0;
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				if (G[i][j] == 'B'){
					sum++;
					ux = dx = i;
					ly = ry = j;
					cnt = 0;
					CL(vs);
					dfs(i,j);
					cout << cnt <<endl;
					int a = max(ry-ly+1,dx-ux+1);
					if (a > m || a > n)continue;
					ans = min(ans,a*a - cnt);
				}
			}
		}
		if (ans != n*m+1){
			printf("%d\n",ans);
		}
		else if (sum == 0){
			printf("1\n");
		}
		else{
			printf("-1\n");
		}
	
	}


	return 0;
}
