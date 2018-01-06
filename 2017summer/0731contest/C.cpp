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
int a[maxn];
int main()
{
	int n;
	LL sum = 0;
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		sum = 0;
		for (int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sort(a,a+n);
		bool flag = 1;
		for (int i = 1;i < n;i++){
			if (a[i]%a[0]!=0){
				flag = 0;
				break;
			}
		}
		if (flag){
			printf("%lld %d\n",sum,a[0]);
		}
		else{
			printf("%d 1\n",sum);
		}
	}


	return 0;
}
