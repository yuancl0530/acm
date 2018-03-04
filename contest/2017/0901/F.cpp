/*********************************
Date: Fri Sep  1 14:24:17 CST 2017
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
LL c[maxn];
LL inv[maxn];
LL quick_mod(LL n , LL m)       //求快速幂
{
    LL ans = 1;
    n %= mod;
    while (m)
    {
        if (m & 1)
            ans = ans * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return ans;
}
void Prepare_inv(LL n,LL M)
{
    inv[1]=1; 
    for (int i=2; i<=n; i++)
        inv[i]=(long long)(M-M/i)*inv[M%i] % M;
}
LL Getc(LL n,LL k)
{
	LL ret=1;
	LL t=n;
	for (int i=0;i<k;i++){
		ret=ret*t%mod;
		t--;
	}
	for (int i=1;i<=k;i++){
		ret=ret*inv[i]%mod;
	}
	return ret;
}
int main()
{
	int T;
	Prepare_inv(1e6+10,mod);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		LL n,m,k;
		LL ans=0;
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		c[0]=1;
		for (int i=1;i<k;i++){
			c[i]=c[i-1]*(k-i+1)%mod*inv[i]%mod;
			//cout<<i<<' '<<c[i]<<endl;
		}
		int tmp=1;
		for (int i=k-1;i>=2;i--){
			tmp=-tmp;
			LL t=(i*quick_mod(i-1,n-1))%mod*c[i]%mod;
			if (tmp==1)
				ans = (ans+t)%mod;
			else
				ans = (ans-t+mod)%mod;
		}
		ans=(ans+(quick_mod(k-1,n-1)*k%mod))%mod;
		ans=ans*Getc(m,k)%mod;
		
		printf("Case #%d: %I64d\n",tt,ans);
	}

	return 0;
}
