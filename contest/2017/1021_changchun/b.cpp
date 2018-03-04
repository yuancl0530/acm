/*********************************
Date: Sat Oct 21 14:15:41 CST 2017
Author: ycl
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL gcd(LL a,LL b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
struct fenshu
{
	LL b;
	LL a;
	fenshu(LL b=0,LL a=0):a(a),b(b){
		LL t=gcd(a,b);
		a/=t;
		b/=t;
	};
	void set(LL bb=0,LL aa=0)
	{
		a=aa;
		b=bb;
		LL t=gcd(a,b);
		a/=t;
		b/=t;
	}
	friend fenshu operator+(LL x,fenshu a)
	{
		return fenshu(x*a.a+a.b,a.a);
	}
	friend fenshu operator/(LL a,fenshu b)
	{
		return fenshu(a*b.a,b.b);
	}
};
LL a[20],b[20];
int main()
{
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt){
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for (int i=1;i<=n;++i)
			scanf("%lld",&b[i]);
		fenshu ans(b[n],a[n]);
		for (int i=n-1;i>=1;--i){
			ans=(a[i]+ans);
			ans=b[i]/ans;
		}
		LL t=gcd(ans.b,ans.a);
		cout<<"Case #"<<tt<<": "<<ans.b/t<<" "<<ans.a/t<<endl;
	}

	return 0;
}
