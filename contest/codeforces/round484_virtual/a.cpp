/*********************************
Date: Sat May 26 12:56:52 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int a[maxn];
char s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i = 0;s[i];++i)
		a[i+1] = s[i]-'0';
	bool ans = true;
	for (int i = 0;i<=n+1;++i){
		int t = 0;
		while (a[i]==0 && i<=n+1){
			++t;
			++i;
		}
		if (a[i] && a[i+1]) {ans=false; break;}
		if (t>=3) {ans=false;break;}
	}
	printf("%s\n",ans? "Yes":"No");
	return 0;
}
