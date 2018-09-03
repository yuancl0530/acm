/*********************************
Date: Fri Aug 24 15:14:00 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int a[maxn],f[maxn];
int main()
{
	cin >> s;
	int n = strlen(s);
	for (int i = 1;i <= n;++i)
		a[i] = a[n+i] = s[i-1] == 'w';
	n <<= 1;
	f[1] = 1;
	int ans = 0;
	for (int i = 2;i <= n;++i){
		f[i] = a[i]!=a[i-1]? f[i-1]+1:1;
		ans = max(ans,f[i]);
	}
	ans = min(ans,n>>1);
	cout << ans << endl;
	return 0;
}
