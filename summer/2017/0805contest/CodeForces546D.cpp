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
const int maxn = 5e6 + 1000;
int prime[maxn];
int cnt = 0;
bool isprime[maxn];
int p[maxn];
LL sum[maxn];
const int maxvalue = 5e6+10;
void creat()
{
	Cl(isprime,true);
	CL(sum);
	CL(p);
	for (int i = 2;i <= maxvalue;i++){
		if (isprime[i]){
			prime[++cnt] = i;
		}
		for (int j = 1;j <= cnt && i*prime[j] <= maxvalue;j++){
			isprime[i*prime[j]] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 2;i < maxvalue;i++){
		if (isprime[i]){
			p[i] = 1;
		}
		else {
			for (int j = 1;j <= cnt;j++){
				if (i % prime[j] == 0){
					p[i] = p[i/prime[j]] + 1;
					break;
				}
			}
		}
		sum[i] = sum[i-1] + p[i];
	}

}
int main()
{
	creat();
	int a,b;
	int t;
	scanf("%d",&t);
	while (t-- && scanf("%d%d",&a,&b) != EOF){
		printf("%lld\n",sum[a]-sum[b]);
	}
	return 0;
}
