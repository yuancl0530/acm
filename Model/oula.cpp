#include <bit/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e7 + 100;
int fp[maxn],pr[maxn],mu[maxn],phi[maxn],mus[maxn];
/*
对[1,n]的数进行欧拉筛。
fp[i]记录i的最小质因数。(可用于质因数分解，也可判断i是否为质数)
pr[i]是质数数组，其中pr[0]为质数个数。
mu[i]为i的莫比乌斯函数，mus[i]为其前缀和。(莫比乌斯函数可以用来容斥和反演)
phi[i]为i的欧拉函数。
*/
void oula_prime(int n)
{
    memset(fp,0,sizeof(fp));
    mu[1]=1;
    pr[0]=0;
    for (int i=2; i<=n; ++i)
    {
        if (!fp[i]) { pr[++pr[0]]=i,fp[i]=i,mu[i]=-1,phi[i]=i-1;}
        for (int j=1; j<=pr[0]; ++j)
        {
            int k=i*pr[j];
            if (k>n) break;
            fp[k]=pr[j];
            if (i%pr[j]==0)
            {
                mu[k]=0,phi[k]=phi[i]*pr[j];
                break;
            }
            else mu[k]=-mu[i],phi[k]=phi[i]*(pr[j]-1);
        }
    }
    mus[0]=0;
    for (int i=1; i<=n; ++i) mus[i]=mus[i-1]+mu[i];
}

int main()
{
	return 0;
}
