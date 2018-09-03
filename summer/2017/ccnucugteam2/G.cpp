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
const int maxn =1e7+5e5;
bool isprime[maxn];
int prime[maxn];
int cnt = 0;
void creat()
{
	Cl(isprime,1);
	CL(prime);
	isprime[1] = 0;
	for (int i = 2;i <= maxn;i++){
		if (isprime[i]){
			prime[++cnt] = i;
		}
		for (int j = 1;j <= cnt && i*prime[j] <= maxn;j++){
			isprime[i*prime[j]] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	creat();
	int n;
	bool flag;
	while (scanf("%d",&n) != EOF){
		flag = 0;
		for (int i = 1;prime[i] < sqrt(n)+1&&i <= cnt;i++){
			if (n % prime[i] == 0){
				int t = n / prime[i];
				for(int j = i + 1;prime[j] <= t &&j<cnt;j++){
					if (t%prime[j]==0 && t/prime[j]>prime[j]&&isprime[t/prime[j]]){
						flag = 1;
				//		printf("%d %d %d\n",prime[i],prime[j],t/prime[j]);
						printf("YES\n");
					}
				}
			}
			if (flag)break;
		}
		if (!flag){
			printf("NO\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
