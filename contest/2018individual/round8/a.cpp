/*********************************
Date: Fri May 25 14:40:58 CST 2018
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
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i = 1;i<n;++i){
		scanf("%d",&a[i]);
	}
	int p = 1;
	while (p < t){
		p += a[p];
	}
	if (p==t) printf("YES\n");
	else printf("NO\n");
	return 0;
}
