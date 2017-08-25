/*********************************
Date: Fri Aug 18 19:54:24 CST 2017
*********************************/
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
int phi(int n)
{
	int ret = n;
	int t = sqrt(n);
	for (int i = 2;i <= t;i++){
		if (n%i==0){
			ret=ret/i*(i-1);
			while (n%i==0)
				n/=i;
		}
	}
	if (n>1)
		ret=ret/n*(n-1);
	return ret;
}
char b[maxn];
int getn(int mod)
{
	LL ret = 0;//爆int
	for (int i = 0;b[i];i++){
		ret = (10*ret + b[i]-'0')%mod;
	}
	return (int)ret;
}
LL Pow(LL a,int n,int mod)
{
	LL ret = 1;
	while (n){
		if (n&1)
			ret = (ret*a)%mod;
		a = (a*a)%mod;
		n>>=1;
	}
	return ret;
}
int main()
{
	int a,c;
	while (scanf("%d%s%d",&a,b,&c) != EOF){
		int n = getn(phi(c));
		LL ans = Pow(a,n,c);
		cout<<ans<<endl;
	}
	return 0;
}
