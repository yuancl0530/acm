#include <stdio.h>
#define ll long long
const int maxn = 1e5 + 100;
int s[maxn],l[maxn],r[maxn],a[maxn];
ll sum[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		l[i] = 0;
		r[i] = n+1;
		sum[i] = sum[i-1] + a[i];
	}
	int top = -1;
	for (int i = 1;i <= n;++i) {
		while (top >=0 && a[s[top]] >= a[i]) --top;
		if (top >= 0) l[i] = s[top];
		s[++top] = i;
	}
	top = -1;
	for (int i = n;i > 0;--i) {
		while (top >=0 && a[s[top]] >= a[i]) --top;
		if (top >= 0) r[i] = s[top];
		s[++top] = i;
	}
	ll ans = 0;
	int t = 1;
	for (int i = 1;i <= n;++i){
		ll tmp = a[i] * (sum[r[i]-1]-sum[l[i]]);
		if (ans < tmp){
			ans = tmp;
			t = i;
		}
	}
	printf("%lld\n%d %d\n",ans,l[t]+1,r[t]-1);
	return 0;
}
