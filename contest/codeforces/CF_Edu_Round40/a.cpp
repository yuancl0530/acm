/*********************************
Date: Thu May 17 22:37:11 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int main()
{
	int n;
	char t;
	int u=0,r=0;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i = 0;i+1 < n;++i){
		if (s[i] != s[i+1] ){
			++i;
			++u;
		}
	}
	printf("%d\n",n-u);
	return 0;
}
