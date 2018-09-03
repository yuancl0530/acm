#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
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
#define Cl(a,b) memset(a,b,sizeof(b))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
char a[maxn];
char b[maxn];
int main()
{
	int t;
	int n,x,y;
	int ans;
	scanf("%d",&t);
	int cnt;
	while (t--){
		scanf("%d%d%d",&n,&x,&y);
		scanf("%s%s",a,b);
		cnt = 0;
		for (int i = 0;i < n;i++){
			if (a[i] != b[i])
				cnt++;
		}
	
	if (n - cnt < x){
		if (y >= min(0, x - cnt) && y <= 2 * n - cnt - x) ans = 0;
		//if (y >= min(0, x - cnt), n - x + min(0, x - cnt)) ans = 0;
	}
	else{
		if (y >= min(0, x - cnt) && y <= x + cnt) ans = 0;
		//if (y >= min(0, x - cnt) && y <= cnt + min(0, x - cnt)) ans = 0;
	}
		
	if (ans)
			printf("Lying\n");
		else 
			printf("Not lying\n");

	}
	return 0;
}
