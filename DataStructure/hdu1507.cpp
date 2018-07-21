/*********************************
Date: Wed Jul 11 23:27:48 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int l[maxn],r[maxn],a[maxn];
int s[maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n){
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			l[i] = 0;
			r[i] = n+1;
		}
		int top = -1;
		for (int i = 1;i <= n;++i){
			while (top > 0 && a[s[top]] >= a[i]) --top;
			if (top > 0) l[i] = s[top];
			s[++top] = i;
		}
		top = -1;
		for (int i = n;i > 0;--i){
			while (top > 0 && a[s[top]] >= a[i]) --top;
			if (top > 0) r[i] = s[top];
			s[++top] = i;
		}
		ll ans = 0;
		for (int i = 0;i <= n;++i)
			ans = max(ans,(ll)a[i]*(r[i]-l[i]-1));
		printf("%lld\n",ans);
	}
	return 0;
}
