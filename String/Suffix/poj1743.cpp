/*********************************
Date: Tue Jul 24 20:01:37 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
#define INF  0x3f3f3f3f
const int mod = 1e9 + 7;
const int maxn = 2e4 + 100;
int wa[maxn],wb[maxn],wu[maxn],wv[maxn];
int height[maxn],sa[maxn];
int a[maxn];
bool cmp(int *y,int a,int b,int j)
{
	return y[a] == y[b]  && y[a+j] == y[b+j];
}
void Suffix(int *s,int n,int m)
{
	int *x = wa,*y = wb,i,j,k,p;
	for (i = 0;i < m;++i) wu[i] = 0;
	for (i = 0;i < n;++i) ++wu[x[i] = s[i]];
	for (i = 1;i < m;++i) wu[i] += wu[i-1];
	for (i = n-1;i >= 0;--i) sa[--wu[x[i]]] = i;
	for (p = j =1;p < n;j <<= 1,m = p){
		for (p = 0,i = n-j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) ++wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i ) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,p = i = 1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	x = wa;
	--n;
	for (i = 1;i <= n;++i) x[sa[i]] = i;
	k  = 0;
	for (i = 0;i < n;height[x[i++]] = k)
		for (k? k--:0,j = sa[x[i]-1];s[i+k] ==s [j+k];++k);
	return ;
}
int n;
bool check(int k)
{
	int ma = -INF;
	int mi = INF;
//	cout<<k<<":"<<endl;
	for (int i = 2;i <= n;++i){
		if (height[i] >=k ){
			ma = max(ma,max(sa[i-1],sa[i]));
			mi = min(ma,min(sa[i-1],sa[i]));
			if (ma - mi > k) return true;
		}
		else {
			ma = -INF;
			mi = INF;
		}
	}
	return false;
}
int main()
{
	while (scanf("%d",&n) != EOF && n){
		for (int i = 0;i < n;++i)
			scanf("%d",&a[i]);
		--n;
		for (int i = 0;i < n;++i)
			a[i] = a[i+1] - a[i] + 88;
		a[n] = 0;
		Suffix(a,n+1,176);
		/*for (int i = 1;i <= n;++i){
			printf("%d :",height[i]);
			for (int j = sa[i];j < n;++j)
				printf("%d ",a[j]);
			printf("\n");
		}*/
	
		int l = 0;
		int r = n;
		while (l+1 < r){
			int mid = (l+r)>>1;
			if (check(mid))
				l = mid;
			else 
				r = mid;
		}
		int ans = l>=4 ? l+1:0;
		printf("%d\n",ans);
	}
	return 0;
}
