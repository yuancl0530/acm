/*********************************
Date: Tue Jul 24 14:44:30 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e3 + 100;
int wa[maxn],wb[maxn],wu[maxn],wv[maxn],sa[maxn],height[maxn];
char s[maxn];
bool cmp(int *y,int a,int b,int j)
{
	return y[a] == y[b] && y[a+j] == y[b+j];
}
void Suffix(int n,int m = 256)
{
	int i,j,p,*x = wa,*y = wb;
	for (i = 0;i < m;++i) wu[i] = 0;
	for (i = 0;i < n;++i) ++wu[x[i] = s[i]];
	for (i = 1;i < m;++i) wu[i] += wu[i-1];
	for (i = n-1;i >= 0;--i) sa[--wu[x[i]]] = i;
	for (p = j = 1;p < n;j<<=1,m = p){
		for (p = 0,i = n-j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) ++wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,p=1,i=1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	--n;
	for (i = 1;i <= n;++i) x[sa[i]] = i;
	for (i = 0,p = 0;i < n;height[x[i++]] = p)
		for (p? --p:0,j = sa[x[i]-1];s[i+p] == s[j+p];++p);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%s",s);
		int n = strlen(s);
		Suffix(n+1);
		int ans = 0;
		for (int i = 1;i <= n;++i)
			ans += n-sa[i]-height[i];
		printf("%d\n",ans);
	}
	return 0;
}
