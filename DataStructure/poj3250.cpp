/*********************************
Date: Thu Jul 12 19:52:59 CST 2018
Author: ycl
*********************************/
#include <stdio.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int s[maxn];
int a[maxn];
int main()
{
	int n;
	int top = -1;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	ll ans = 0;
	s[++top] = n+1;
	for (int i = n;i > 0;--i){
		while (top > 0 && a[s[top]] < a[i]) --top;
		ans += s[top] - i -1;
		s[++top] = i;
	}
	printf("%lld\n",ans);
	return 0;
}
