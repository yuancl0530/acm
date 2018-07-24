#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2e4+100;
int wa[maxn],wb[maxn],wu[maxn],wv[maxn],sa[maxn];
int a[maxn];
bool cmp(int *y,int a,int b,int j)
{
	return y[a] == y[b] && y[a+j] == y[b+j];
}
void Suffix(int *s,int n,int m=1000)
{
	int *x = wa,*y = wb,i,j,k,p;
	for (i = 0;i < m;++i) wu[i] = 0;
	for (i = 0;i < n;++i) ++wu[x[i]=s[i]];
	for (i = 1;i < m;++i) wu[i] += wu[i-1];
	for (i = n-1;i >= 0;--i) sa[--wu[x[i]]] = i;
	for (p = 1,j = 1;p < n;j <<= 1,m = p){
		for (p = 0,i = n-j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < n;++i) ++wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,p = 1,i = 1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
}
/*****height******/
int height[maxn],Rank[maxn];
void calheight(int *s,int n)
{
	int i,j,k = 0;
	for (i = 1;i <= n;++i) Rank[sa[i]] = i;
	for (i = 0;i < n;height[Rank[i++]] = k)
		for (k? --k:0,j = sa[Rank[i]-1];s[i+k] == s[j+k];++k);
}

int n;
bool check(int k)
{
	int mi = sa[1];
	int ma = sa[1];
	int t = 2;
	while (t <= n){
		while (t <= n && height[t] >= k){
			ma = max(ma,max(sa[t],sa[t-1]));
			mi = min(mi,min(sa[t],sa[t-1]));
			++t;
			if (ma-mi >= k) return true;
		}
		//cout<< k <<" "<<ma<<" "<<mi<<endl;;
		++t;
		mi = n+1;
		ma = 0;
	}
	return false;
}
int main()
{
	while (scanf("%d",&n) != EOF && n){
		for (int i = 0;i < n;++i)
			scanf("%d",&a[i]);
		a[n] = 0;
		for (int i = 0;i < n;++i)
			a[i] = a[i+1] - a[i] + 88;
		Suffix(a,n+1);
		calheight(a,n);
		/*for (int i = 1;i <= n;++i){
			for (int j = sa[i];j < n;++j)
				cout<<a[j]<<" ";
			cout<<endl;
		}
		for (int i = 1;i <= n;++i)
			cout<<height[i]<<" ";
		cout<<endl;*/
		int l = 4;
		int r = n;
		while (l + 1 < r){
			int mid = (l+r)>>1;
			if (check(mid))
				l = mid;
			else 
				r = mid;
		}
		int ans = check(l)? l+1 : 0;
		printf("%d\n",ans);
	}
	return 0;
}
