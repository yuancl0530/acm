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
		ans = 1;
		if (x > y)
			swap(x,y);
		if (n - cnt < x){
			x -= n-cnt;
			y -= n-cnt;
			cnt -= 2 * x;
		}
		y -= x;
		if (y <= cnt){
			printf("Not lying\n");
		}
		else{
			printf("Lying\n");
		}

	}
	return 0;
}
