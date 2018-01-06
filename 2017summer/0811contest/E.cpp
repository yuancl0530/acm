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
LL Pa[maxn];
int cnt = 0;
bool isprime(LL n)
{
	LL t = sqrt(n);
	bool ret = 1;
	Pa[++cnt] = n;
	for (LL i = 2;i <= t;i++){
		if (n%i==0){
			Pa[++cnt] = i;
			Pa[++cnt] = n/i;
			ret = 0;
		};
	}
	return ret;
}
int main()
{
	LL a,b;
	while (scanf("%lld%lld",&a,&b) != EOF){
		LL ans = 0;
		cnt = 0;
		bool pa = isprime(a);
		sort(Pa+1,Pa+1+cnt);
		if (a > b && pa){
			printf("%lld\n",b);
			continue;
		}
		else if (a<=b&&pa){
			LL m = b/a;
			ans+=b-a*m+m;
			printf("%lld\n",ans);
			continue;
		}
		else{
			while (b){
				for (int i = cnt;i >= 1;i--){
					if (b%Pa[i] == 0){
						
					}
				}
			}	
		}
		printf("%lld\n",ans);
		
	}


	return 0;
}
