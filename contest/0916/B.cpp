
#include<iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
#define LL long long
const int maxn = 1e7+1;
const int M = 1e9+7;
int T,p,q,k;
ll a,b,c,x,y,sum;

ll qpow(int A,int B)
{
    ll ans = 1;
    while (B)
    {
        if (B & 1) ans = (ans * A) % M;
        A = A*A % M;
        B = B >> 1;
    }
    return ans;
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

int main()
{
    scanf("%d",&T);
    while (T--)
    {
		scanf("%d%d%d",&p,&q,&k);
		LL t=p-q;
		LL t1=qpow(p-2*q,k);
		LL t2=qpow(p,k);
		t1=((2+t1)%M*500000004%M;
		LL ans=t1*inv(t2,M)%M;
    	printf("%lld\n",ans);
    }
    return 0;
}
