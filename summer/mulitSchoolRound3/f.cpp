/*********************************
Date: Mon Jul 30 12:58:37 CST 2018
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
int a[maxn];
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int s = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			s ^= a[i];	
		}
		for (int i = 1;i < n;++i)
			scanf("%*d%*d");
		bool ans = 0;
		for (int i = 1;i <= n;++i)
			if (a[i] > (a[i]^s)){
				ans = true;
				break;
			}
		if (ans)
			printf("Q\n");
		else
			printf("D\n");
	}
	return 0;
}
