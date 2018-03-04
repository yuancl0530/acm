#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    ll n,m;
	ll an;
    while(scanf("%lld%lld%lld",&n,&m,&an)!=EOF){
        if(n>m)
        swap(n,m);
		ll ans;
        ll t=1+gcd(n-1,m-1)*2;
        if(t!=3){
            ll onex=(t/2-1);
            ll mm=(m%(t-1)==1)?2*(m/(t-1)):2*(m/(t-1))+1;
            ll nn=(n%(t-1)==1)?(2*(t/2-1)*(n/(t-1))):(2*(t/2-1)*(n/(t-1))+(t/2-1));
            ll all=(n+n+m+m-1)/(t-1);
            ans=nn*mm+all;
        }
        else{
            ans=(n+n+m+m-1)/(t-1)-1;
        }
		if (an!=ans)cout<<n<<" "<<m<<" "<<ans<<" "<<an<<endl;
    }
    return 0;
}
