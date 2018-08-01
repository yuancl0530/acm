/*********************************
Date: Mon Jul  9 16:12:06 CST 2018
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
int s[maxn],a[maxn];
int top = -1;
int bsearch(int k)
{
	int l = -1;
	int r = top;
	while (l+1 < r){
		int mid = (l+r)>>1;
		if (a[s[mid]] <= a[k])
			r = mid;
		else
			l = mid;
	}
	return s[r];
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	s[++top] = 1;
	int ans = 0;
	for (int i = 2;i <= n;++i){
		if (a[s[top]] > a[i])
			s[++top] = i;
		else {
			ans = max(ans, i-bsearch(i));
		}
	}
	printf("%d\n",ans);
	return 0;
}
