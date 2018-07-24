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
#define INF 0x7fffffff
const int maxn = 1e3+10;
int a[maxn];
int dp[maxn];
int main()
{
	int n;
	int m;

	while (scanf("%d",&n) != EOF && n){
		CL(a);
		CL(dp);
		int Max = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",a+i);
		}
		scanf("%d",&m);
		if (m < 5){
			printf("%d\n",m);
			continue;
		}
		sort(a+1,a+1+n);
		m -= 5;
		for (int i = 1;i < n;i++){
			for (int j = m;j >= a[i];j--){
				dp[j] = max(dp[j],dp[j-a[i]] + a[i]);
			}
		}
		printf("%d\n",m - dp[m] - a[n] + 5);
	
	}
	return 0;
}

