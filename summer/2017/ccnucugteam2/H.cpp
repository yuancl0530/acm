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
LL f[15];
int main()
{
	int n,m;
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	f[1] = 8;
	for (int i = 2;i < 10;i++){
		f[i] = f[i-1]*9;
	}
	while (scanf("%d",&n) != EOF){
		int t = min(n,9);
		printf("%lld",f[t]);
		for (int i = 10;i <= n;i++){
			printf("0");
		}
		printf("\n");
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
