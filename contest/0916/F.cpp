/*********************************
Date: Sat Sep 16 15:01:44 CST 2017
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
#define ll long long
const int MOD = 998244353;
const int maxn = 1e6 + 100;
LL f[maxn];
void Init()
{
	f[0]=1;
	for (int i=1;i<=10000;i++)
		f[i]=i*f[i-1];
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
int g(LL n,LL k)
{
	if (n%2 == k%2){
		if ((n-k)/2%2==0)
			return 1;
		else
			return -1;
		return 1;
	}
	return 0;
}
LL fun(LL a,LL b)
{
	LL ret=1;
	LL aa=abs(a);
	LL bb=abs(b);
	if (aa > bb){
		while (aa>bb){
			ret*=aa;
			aa-=2;
		}
		if (a*b<0)
			return -ret;
		return ret;
	}
	else{
		while (bb>aa){
			ret*=bb;
			bb-=2;
		}
		if (a*b<0)
			return -inv(ret,MOD);
		return inv(ret,MOD);
	}

}

int main()
{
	Init();
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		if (n&1){
			int k=(m+1)/2;
			LL t1=fun(n+2*k-3,n+1-2*k);
			int flag=g(n,m);
			t1=t1*n%MOD;
			LL t2=inv(f[2*k-1],MOD);
			LL ans=t1*t2%MOD;
			ans*=flag;
			ans=(ans+MOD)%MOD;
			printf("%lld\n",ans);
		}
		else{
			int k=m/2;
			int flag;
			flag=g(n,m);
			LL t1=fun(n+2*k-2,n-2*k);
			t1=t1*n%MOD;
			LL t2=inv(f[2*k],MOD);
			LL ans=t1*t2%MOD;
			ans*=flag;
			ans=(ans+MOD)%MOD;
			printf("%lld\n",ans);
		}
	
	}
	return 0;
}
