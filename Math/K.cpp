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
int prime[maxn];
int isprime[maxn];
int a[maxn];
int mu[maxn];
void oula()
{
	int n = 1e5;
	Cl(isprime,1);
	for (int i = 2;i <= n;i++){
		if (isprime[i]){ prime[++prime[0]]=i;mu[i]=-1;}
		for (int j = 1;j <= prime[0];j++){
			int k = i*prime[j];
			if (k>n)break;
			isprime[k]=0;
			if (i%prime[j]==0){
				mu[k]=0;
				break;
			}
			else{
				mu[k]=-mu[i];
			}
		}
	}
}
int n,Min;
int solve()
{
	LL ans = 0;
	LL s = 1;
	for (int i = 1;i<=prime[0];i++){
		s = 1;
		if (prime[i]>Min)break;
		for (int j = 1;j <= n;j++){
			s = (s*(a[j]/prime[i]))%MOD;
		}
		if (mu[prime[i]]==-1){
			ans = (ans+s)%MOD;
		}
		else{
			ans = (ans-s+MOD)%MOD;
		}
	}
	return (int)ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	int t = 0;
	oula();
	while (T--){
		scanf("%d",&n);
		Min = INF;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			Min = min(Min,a[i]);
		}
		int ans = solve();
		printf("Case %d: %d\n",++t,ans);
	}

	return 0;
}
