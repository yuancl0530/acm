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

int main()
{
	int n,m;
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	while (scanf("%d%d",&n,&m) != EOF){
		m = min(n,m);
		int ans = 2*n/m;
		if (2*n%m)ans++;
		printf("%d\n",ans);
		m = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
