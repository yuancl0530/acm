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
int prime[maxn];
bool isprime(int n)
{
	if (n == 1 || n== 2)return 1;
	for (int i = 2;i <= sqrt(n);i++){
		if (n%i==0)
			return 0;
	}
	return 1;
}
int mu(int x);
LL fun(int n,int k)
{
	int t = pow(n,k);
	LL ret = 0;
	for (int i = 1;i <= t;i++){
		ret = (ret + mu(i)*(LL)sqrt((int)(t/i)))%MOD;
	}
	return ret;
}
int cnt = 0;
int mu(int x)
{
	if (x == 1)
		return 1;
	for (int i = 1;i<=cnt;i++){
		if (x % (prime[i] * prime[i])==0)
			return 0;
	}
	return 1;
}
int main()
{
	for (int i = 2;i <= 10000;i++){
		if (isprime(i)){
			prime[++cnt] = i;
		}
	}
	int n,k;
	LL ans = 0;
	for (int i = 1;i < 8;i++){
		for (int j = 1;j < 6;j++){
			printf("n=%d k=%d %lld\n",i,j,fun(i,j));
		}
	}
	
/*	for (int i = 2;i <= 100;i++){
		if (mu(i)){
			cout <<i<<endl;
		}
	}
*/
	return 0;
}
