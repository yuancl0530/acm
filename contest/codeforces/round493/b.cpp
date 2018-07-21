/*********************************
Date: Sun Jul  1 22:19:04 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e2 + 100;
int a[maxn];
int b[maxn];
int num0[maxn];
int f[maxn];
int main()
{
	int n,w;
	scanf("%d%d",&n,&w);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		num0[i] = num0[i-1];
		if (a[i] %2 == 0) ++num0[i];
	}
	int cnt = 0;
	for (int i = 1;i < n;++i){
		if (i%2==0 && i == 2*num0[i]){
			b[cnt++] = abs(a[i]-a[i+1]);
		}
	}
	sort(b,b+cnt);
	int ans = 0;
	for (int i = 0;i < cnt;++i){
		if (w >= b[i]) {
			++ans;
			w -= b[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
