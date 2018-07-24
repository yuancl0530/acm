/*********************************
Date: Wed Jul  4 13:31:08 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int ans[maxn];// >0 < 1
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d%s",&n,s+1);
		if (s[n-1] >= s[n])
			ans[n-1] = 1;
		else
			ans[n-1] = 0;
		for (int i = n-2;i > 0;--i) {
			if (s[i] == s[i+1])
				ans[i] = ans[i+1];
			else if (s[i] > s[i+1])
				ans[i] = 1;
			else 
				ans[i] = 0;
		}
		for (int i = 1;i < n;++i){
			printf("%c",ans[i]==1? '>':'<');
		}
		printf("\n");
	}
	return 0;
}
