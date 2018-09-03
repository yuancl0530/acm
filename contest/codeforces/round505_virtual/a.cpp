/*********************************
Date: Fri Aug 24 13:38:12 CST 2018
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
int cnt[30];
int main()
{
	int n;
	cin >> n >> s;
	for (int i = 0;s[i];++i) ++cnt[s[i]-'a'];
	int t = 0;
	for (int i = 0;i < 26;++i) 
		if (cnt[i] >= 2) ++t;
	if (t || n==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
