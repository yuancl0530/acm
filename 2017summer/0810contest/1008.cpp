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
const int maxn = 5e3 + 100;
char str[maxn];
int a[maxn];
int main()
{
	int T;
	int ans;
	scanf("%d",&T);
	int k,l,sum;
	while (T--){
		ans = 0;
		int m;
		scanf("%d%s",&m,str);
		int len = strlen(str);
		for (int i = 1;i < len-1;i++){
			k = 0;
			for (int j = 1;i-j>=0 && i+j<len ;j++){
			    //if (i-j<0 || i+j>=len) break;
				a[++k] = abs(str[i-j] - str[i+j]);
			}
			l = 1;
			sum = 0;
			for (int j = 1;j <= k;j++){
				sum += a[j];
				if (sum <= m){
					ans = max(j-l+1,ans);
				}
				else{
					while (m < sum && sum && l <= j){
						sum -= a[l];
						l++;
					}
					if (sum)
						ans = max(j-l+1,ans);
				}
			}
		}
		
		for (int i = 0; i < len-1;i++){
			k = 0;
			for (int j = 0;i-j >= 0&&i+1+j < len;j++){
		//		if (i-j < 0 || i+1+j >= len)break;
				a[++k] = abs(str[i-j]-str[i+1+j]);
			}
			sum = 0;
			l = 1;
			for (int j = 1;j <= k;j++){
				sum += a[j];
				if (sum <= m){
					ans = max(j-l+1,ans);
				}
				else{
					while (m < sum && sum && l <= j){
						sum -= a[l];
						l++;
					}
					if (sum)
						ans = max(j-l+1,ans);
				}
			}
		}
		printf("%d\n",ans);

	}

	return 0;
}
