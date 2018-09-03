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
int b[maxn];
int a[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	int n,m;
	while (t--){
		scanf("%d%d",&n,&m);
		int sum = 0;
		for (int i = 0;i <= m;i++){
			scanf("%d",&a[i]);
		}
		a[0] =0;
		for (int i = 1;i <= m;i++){
			int cnt = 0;
			for (int j = 1;j < i;j++){
				if (a[i-j] ){
					cnt++;
				}
			}
			b[i] = a[i] - cnt/2;
			if (a[i])
				sum++;
			if (sum == n)
				break;
		}
		int tot = 0;
		for (int i = 1;i <= m;i++){
			for (int j = 0;j < b[i];j++){
				printf("%d ",i);
				tot++;
			}
			if (tot == sum)break;
		}
		printf("\n");
	}


	return 0;
}
