#include <bits/stdc++.h>
#define maxn 20000000
#define LL long long int
using namespace std;

int isprime[maxn+10];
int prime[maxn/10];
int num[maxn+10];
LL S[maxn+10];
LL quick_pow(LL x,LL n)
{
   return 1ll<<n;
}
void askprime()
{
    fill(isprime,isprime+maxn+10,1);
    isprime[0]=isprime[1]=0;
    num[1]=0;
    int cnt=0;
    for(int i=2;i<=maxn;i++)
    {
        if(isprime[i]) prime[cnt++]=i,num[i]=1;
        for(int j=0;j<cnt&&1ll*i*prime[j]<=maxn;j++)
        {
            isprime[i*prime[j]] = 0;
            if(i%prime[j]==0)
            {
                int x=i/prime[j];
                if(x%prime[j]==0) num[i*prime[j]]=-1;
                else num[i*prime[j]] = num[x];
                break;
            }
            else
                num[i*prime[j]] = num[i]==-1?-1:num[i]+1;
        }
    }
	num[0] = 0;
    for(int i=1;i<=maxn;i++)
    {
        if(num[i]==-1) S[i]=S[i-1];
        else S[i]=S[i-1]+quick_pow(2LL,(long long int)(num[i]));
    }
}
int main()
{
    askprime();
    int t;
	cin>>t;
    while(t--)
    {
        int n;
		scanf("%d",&n);
        printf("%lld\n",S[n]);
    }
    return 0;
}
