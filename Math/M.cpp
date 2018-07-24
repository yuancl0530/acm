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
#define LL unsigned long long
int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL phi[maxn];
int prime[maxn];
int f[5050];
void oula()
{
	int n = 1e5;
	bool isprime[maxn];
	Cl(isprime,1);
	for (int i = 2;i <= n;i++){
		if (isprime[i]) {phi[i] = i-1;prime[++prime[0]] = i;}
		for (int j = 1;j <= prime[0];j++){
			int k = i*prime[j];
			if (k > n)break;
			if (i%prime[j] == 0){
				phi[k] = phi[i]*prime[j];
				isprime[k] = 0;
				break;
			}
			else{
				isprime[k] = 0;
				phi[k] = phi[i]*(prime[j]-1);
			}
		}
	}
}
LL Plus(LL a,LL b,LL mod)
{
	LL ans = 0;
	while (b){
		if (b&1)
			ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}
LL Pow(LL a,LL n,int mod)
{
	LL ret = 1;
	a%=mod;
	while (n){
		if (n&1)
			ret = Plus(ret,a,mod);
		a = Plus(a,a,mod);
		n>>=1;
	}
	return ret;
}
LL search(int c)
{
	f[0]=0,f[1]=1;
	for (int i = 2;i<=5000;i++){
		f[i] = (f[i-1]+f[i-2])%c;
		if (f[i]==1&&f[i-1]==0)
			return i-1;
	}
	return -1;
}
int main()
{
	oula();
	f[0] = 0,f[1]=1;
	LL a,b,n;
	int c;
	int T;
	scanf("%d",&T);
	int t = 0;
	phi[1] = 1;
	while (T--){
		scanf("%I64u%I64u%I64u%d",&a,&b,&n,&c);  
		LL loop1 = search(c);
		LL p =phi[c];
		LL t1 = Pow(a,b,loop1);
		LL temp1 = f[t1]%c;
		LL loop2 = search(p);
		LL t2 = Pow(a,b,loop2);
		LL temp2 = f[t2]%p;
		temp2 = Pow(temp2,n-1,p)+p;
		LL ans = Pow(temp1,temp2,c);
		printf("Case %d: %I64u\n",++t,ans);
	}
	return 0;
}
