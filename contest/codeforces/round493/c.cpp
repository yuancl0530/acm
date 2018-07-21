/*********************************
Date: Sun Jul  1 22:37:13 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int a[maxn];
int main()
{
	int n;
	ll x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	scanf("%s",s);
	int cnt = 0;
	int num0 = 0;
	int num1 = 0;
	for (int i = 0;i < n;){
		int t = s[i] - '0';
		if (!t) ++num0;
		else ++num1;
		a[cnt++] = t;
		++i;
		while (i < n && s[i]-'0' == t) ++i;
	}
	ll ans = num0*y;
	for (int i=1;i <= num0;++i){
		ans = min(ans,i*y+(num0-i)*x);
	}
	printf("%lld\n",ans);
	return 0;
}
