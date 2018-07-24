#include<bits/stdc++.h>
using namespace std;

#define bll long long

const int maxn = 1e5+100;
const int mod = 1e9+7;
int a[maxn];
bll p[maxn];

int main()
{
    a[1] = a[2] = 1;
    for (int i=3;i<=100000;i++)
        a[i] = a[i-a[i-1]] + a[i-1-a[i-2]];
    p[1] = 1;
    for (int i=2;i<=100000;i++)
        p[i] = (p[i-1]+a[i]) % mod;

    bll n;
	cin>>n;
    while (scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",p[n]);
    }
    
    /*int n,x,ans;
    while (scanf("%d",&n)!=EOF)
    {
        x = n;
        ans = 0;
        for (int i=0;p[i]<=x;i++)
            ans += x/p[i];
        printf("%d\n",ans+1);
    }*/
    return 0;
}

