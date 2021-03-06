/*********************************
Date: Thu Jul 26 09:22:14 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
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
char s[maxn],t[maxn];
bool cmp(int *y,int a,int b,int j)
{
	return y[a] == y[b] && y[a+j] == y[b+j];
}
void Sufffix(int n,int m)
{
	int *x = wa, *y = wb,i,j,p;
	for (i = 0;i < m;++i) wu[i] = 0;
	for (i = 0;i < n;++i) ++wu[x[i] = s[i]];
	for (i = 1;i < m;++i) wu[i] += wu[i-1];
	for (i = n-1;i >= 0;--i) sa[--wu[x[i]]]  = i;

	for (p = j = 1;p < n;j <<= 1,m = p){
		for (p = 0, i = n-j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) ++wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,i = p = 1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	x = wa;
	--n;
	for (i = 1;i <= n;++i) x[sa[i]] = i;
	for (i = p = 0;i < n;height[x[i++]] = p)
		for (p? --p:0,j = sa[x[i]-1];s[i+p] == s[j+p];++p);
}
struct {
	int v,cnt;
}S[maxn];
int main()
{
	int k;
	while (scanf("%d",&k) != EOF && k){
		scanf("%s%s",s,t);
		int n = strlen(s);
		int mid = n;
		int m = strlen(t);
		s[mid] = '$';
		int i = 0;
		++n;
		while (i < m) s[n++] = t[i++];
		s[n] = 0;
		Sufffix(n+1,128);
		/*for (int i = 1;i <= n;++i){
			if (height[i] < k) printf("\n");
			printf("%d %s\n",height[i],s+sa[i]);
		}*/
		ll ans = 0;
		int top = -1;
		int cnt = 0;
		ll sum = 0;
		for (int i = 1;i <= n;++i){
			if (height[i] >= k){
				cnt = 0;
				while (top >= 0  && height[i] < S[top].v){
					sum -= (ll)(S[top].v-k+1) * S[top].cnt;
					sum += (ll)(height[i]-k+1) * S[top].cnt;
					cnt += S[top--].cnt;
				}
				S[++top].v = height[i];
				if (sa[i-1] < mid){
					sum += (ll)(height[i]-k+1);
					S[top].cnt = ++cnt;
				}
				else S[top].cnt = cnt;
				if (sa[i] > mid){
					ans += sum;
				}
			}
			else{
				sum = 0;
				top = -1;
			}
			/*cout<<i<<" "<<ans<<" "<<" "<<sum<<endl;
			for (int i = 0;i <= top;++i)
				printf("(%d,%d)\n",S[top].v,S[top].cnt);
			cout<<endl;*/
		}
		sum = cnt = 0;
		for (int i = 1;i <= n;++i){
			if (height[i] >= k){
				cnt = 0;
				while (top >= 0  && height[i] < S[top].v){
					sum -= (ll)(S[top].v-k+1) * S[top].cnt;
					sum += (ll)(height[i]-k+1) * S[top].cnt;
					cnt += S[top--].cnt;
				}
				S[++top].v = height[i];
				if (sa[i-1] > mid){
					sum += (ll)(height[i]-k+1);
					S[top].cnt = ++cnt;
				}
				else S[top].cnt = cnt;
				if (sa[i] < mid){
					ans += sum;
				}
			}
			else{
				sum = 0;
				top = -1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

