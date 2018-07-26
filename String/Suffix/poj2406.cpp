/*********************************
Date: Wed Jul 25 09:05:28 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
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
	for (p = j = 1;p < n;j <<= 1,m = p){
		for (p = 0,i = n - j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) ++ wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,p = i = 1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	x = wa;
	--n;
	for (i = 1;i <= n;++i) x[sa[i]] = i;
	for (p = i = 0;i < n;height[x[i++]] = p)
		for (p? p--:0,j = sa[x[i]-1];s[i+p] == s[j+p];++p);
}
int st[maxn];
void build(int n)
{
	int t = wa[0];
	st[t-1] = height[t];
	for (int i = t-2;i >= 1;--i)
		st[i] = min(height[i+1],st[i+1]);
	
}
int solve()
{
	int n = strlen(s);
	Suffix(n+1);
	build(n);
	/*for (int i = 1;i <= n;++i)
		printf ("%d %s\n",st[i],s+sa[i]);
	*/
	
	for (int i = 1;i < n;++i){
		if (n % i) continue;
		else {
			int r = wa[0];
			int l = wa[i];
			if (l >= r) continue;
	//		cout<<i<<" "<<l<<" "<<r<<" "<<st[l]<<endl;
			if (st[l] == n-i) return n/i;
		}
	}
	return 1;
}
int main()
{
	while (scanf("%s",s) != EOF && s[0] != '.'){
		printf("%d\n",solve());
	}
	return 0;
}
