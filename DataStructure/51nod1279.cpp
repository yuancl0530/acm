/*********************************
Date: Mon Jul  9 16:32:54 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 5e4 + 100;
int s[maxn],a[maxn],b[maxn],cnt[maxn];
int top = -1;
int rr;
int b_search(int k)
{
	if (k > a[s[0]]) rr = 0;
	if (rr == 0) return false;
	int l = 0;
	int r = rr;
	while (l+1 < r){
		int mid = (l+r)>>1;
		if (cnt[s[mid]] && a[s[mid]] >= k)
			l = mid;
		else 
			r = mid;
	}
	if (l <= top && cnt[s[l]] && a[s[l]] >= k){
		--cnt[s[l]];
		if (!cnt[s[l]]) rr = l;
		else rr = l+1;
		return true;
	}
	return false;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	for (int i = 1;i <= m;++i)
		scanf("%d",&b[i]);
	s[++top] = 1;
	++cnt[1];
	for (int i = 2;i <= n;++i){
		if (a[s[top]] > a[i]) {
			s[++top] = i;
			++cnt[i];
		}
		else
			++cnt[s[top]];
	}
	int ans = 0;
	rr = top+1;
	for (int i = 1;i <= m;++i) {
		if (b_search(b[i])) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
